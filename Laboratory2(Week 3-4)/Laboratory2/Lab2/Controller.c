#include "Controller.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

Controller* createController(ProductRepo* r)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
	c->undoStack = createStack();
	c->redoStack = createStack();
	c->canRecord = 1;
	return c;
}

void destroyController(Controller * c)
{

	destroyRepo(c->repo);
	destroyStack(c->undoStack);
	destroyStack(c->redoStack);

	free(c);
}

int addProductCtrl(Controller* c, char* name, char* type, double quantity, struct tm s)
{
	Product* p = createProduct(name, type, quantity, s);

	int res = addProduct(c->repo, p);

	if (res == 1 && c->canRecord) // if the product was successfully added - register the operation
	{
		if (c->redoStack->length > 0) {
			destroyStack(c->redoStack);
			c->redoStack = createStack();
			//c->canRecord = 0;
		}
		Operation* o = createOperation(p, "add");
		push(c->undoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
	}
	else if (res == -1 && c->canRecord) {
		if (c->redoStack->length > 0) {
			destroyStack(c->redoStack);
			c->redoStack = createStack();
			//c->canRecord = 0;
		}

		Operation* o = createOperation(p, "addQ");
		push(c->undoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
	}

	// destroy the product that was just created, as the repository stored a copy
	destroyProduct(p);

	return res;
}

ProductRepo* getRepo(Controller* c)
{
	return c->repo;
}

int undo(Controller* c)
{
	if (isEmpty(c->undoStack))
	{
		return 0;
	}

	Operation* operation = pop(c->undoStack);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Product* product = getProduct(operation);

		Operation* o = createOperation(product, "add");
		push(c->redoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
		char name[50];
		char type[50];
		strcpy(name, getName(product));
		strcpy(type, getType(product));
		deleteProduct(c->repo, name, type);
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		Product* product = getProduct(operation);

		Operation* o = createOperation(product, "remove");
		push(c->redoStack, o);

		addProduct(c->repo, product);
	}
	else if (strcmp(getOperationType(operation), "addQ") == 0) {
		Product* product = getProduct(operation);
		Operation* o = createOperation(product, "addQ");
		push(c->redoStack, o);
		product->quantity = -product->quantity;

		addProduct(c->repo, product);
	}
	else if (strcmp(getOperationType(operation), "update") == 0) {
		Operation* operationNew = pop(c->undoStack);
		Product* old = getProduct(operation);
		Product* new = getProduct(operationNew);
		updateProduct(c->repo, old, new->name, new->type);
		push(c->redoStack, operation);
		push(c->redoStack, operationNew);
		destroyOperation(operationNew);
	}

	// the operation must be destroyed
	destroyOperation(operation);
	c->canRecord = 1;
	return 1;

}




ProductRepo* searchCtrl(Controller* c, char* s, SearchFilter sorter) {
	ProductRepo* auxRepo = createRepo();
	for (int i = 0; i < getRepoLength(c->repo); i++) {
		Product* p = getProductOnPos(c->repo, i);
		if (strstr(getName(p), s))
		{
			addProduct(auxRepo, p);
		}
	}
	for (int i = 0; i < getRepoLength(auxRepo) - 1; i++)
		for (int j = i+1; j < getRepoLength(auxRepo); j++)
			if ((*sorter)(auxRepo, getProductOnPos(auxRepo, i), getProductOnPos(auxRepo, j)))
			{
				Product* aux = getProductOnPos(auxRepo, i);
				auxRepo->products->elems[i] = auxRepo->products->elems[j];
				auxRepo->products->elems[j] = aux;
			}
	return auxRepo;

}

ProductRepo* sort(Controller* c, SearchFilter sorter){
	ProductRepo* auxRepo = getRepo(c);
	for (int i = 0; i < getRepoLength(auxRepo) - 1; i++)
		for (int j = i + 1; j < getRepoLength(auxRepo); j++)
			if ((*sorter)(auxRepo, getProductOnPos(auxRepo, i), getProductOnPos(auxRepo, j)))
			{
				Product* aux = getProductOnPos(auxRepo, i);
				auxRepo->products->elems[i] = auxRepo->products->elems[j];
				auxRepo->products->elems[j] = aux;
			}
	return auxRepo;
}

int sortByQuantity(ProductRepo* auxRepo, Product* p1, Product* p2) {
	return (p1->quantity < p2->quantity);
}

int sortByName(ProductRepo* auxRepo, Product* p1, Product* p2) {
	return strcmp(p1->name, p2->name) < 0;
}
int sortByNameDesc(ProductRepo* auxRepo, Product* p1, Product* p2) {
	return !sortByName(auxRepo, p1, p2);
}
int sortByQuantityDesc(ProductRepo* auxRepo, Product* p1, Product* p2) {
	return !sortByQuantity(auxRepo, p1, p2);
}

int deleteCtrl(Controller* c, char* name, char* type) {
	Product* p = copyProduct(find(c->repo, name, type));
	int res =  deleteProduct(c->repo, name, type);

	if (res && c->canRecord) {
		if (c->redoStack->length > 0) {
			destroyStack(c->redoStack);
			c->redoStack = createStack();
			//c->canRecord = 0;
		}
		Operation* o = createOperation(p, "remove");
		push(c->undoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
	}
	destroyProduct(p);
	return res;

}

int updateCtrl(Controller* c, char* name, char* type, double quantity, struct tm s, char* oldName, char* oldType) {
	Product* pNew = createProduct(name, type, quantity, s);
	Product* pOld = copyProduct(find(c->repo, oldName, oldType));
	int rez = updateProduct(c->repo, pNew, oldName, oldType);
	if (rez && c->canRecord) {
		if (c->redoStack->length > 0) {
			destroyStack(c->redoStack);
			c->redoStack = createStack();
			//c->canRecord = 0;
		}
		Operation* o = createOperation(pNew, "update");
		Operation* o1 = createOperation(pOld, "update");
		push(c->undoStack, o);
		push(c->undoStack, o1);
		destroyOperation(o1);
		destroyOperation(o);
	}
	destroyProduct(pOld);
	destroyProduct(pNew);

	return rez;
}


ProductRepo* getProductByType(Controller* c, char* type) {
	ProductRepo* auxRepo = createRepo();
	for (int i = 0; i < getRepoLength(c->repo); i++) {
		Product* p = getProductOnPos(c->repo, i);
		if (strstr(getType(p), type))
		{
			addProduct(auxRepo, p);
		}
	}
	return auxRepo;
}

ProductRepo* filterByDate(ProductRepo* p, int days, struct tm* s) {
	ProductRepo* auxRepo = createRepo();
	for (int i = 0; i < getRepoLength(p); i++) {
		Product* prdct = getProductOnPos(p, i);
		time_t t = time(NULL);
		struct tm* ts;
		ts = localtime(&t);
		double diffDays = DifferentDate(ts->tm_mday, ts->tm_mon+1, ts->tm_year, prdct->expirationDate.tm_mday, prdct->expirationDate.tm_mon, prdct->expirationDate.tm_year - 1900);
		if (days > diffDays) {
			addProduct(auxRepo, prdct);
		}
	}
	return auxRepo;
}


ProductRepo* filterByQuantity(Controller* c, double quantity, Filter filter) {
	ProductRepo* auxRepo = createRepo();
	for (int i = 0; i < getRepoLength(c->repo); i++) {
		Product* prdct = getProductOnPos(c->repo, i);
		if ((*filter)(quantity, prdct)) {
			addProduct(auxRepo, prdct);
		}
	}
	return auxRepo;
}


int filterQuantityBigger(double quantity, Product* p) {
	return quantity < p->quantity;
}

int filterQuantitySmaller(double quantity, Product* p) {
	return quantity > p->quantity;
}


int DifferentDate( int day1,int mon1, int year1, int day2, int mon2,int year2){
	int ref, dd1, dd2, i;
	ref = year1;
	if (year2<year1)
		ref = year2;
	dd1 = 0;
	dd1 = dater(mon1);
	for (i = ref; i<year1; i++)
	{
		if (i % 4 == 0)
			dd1 += 1;
	}
	dd1 = dd1 + day1 + (year1 - ref) * 365;
	dd2 = 0;
	for (i = ref; i<year2; i++)
	{
		if (i % 4 == 0)
			dd2 += 1;
	}
	dd2 = dater(mon2) + dd2 + day2 + ((year2 - ref) * 365);
	return dd2-dd1;
}

int dater(x)
{
	int y = 0;
	switch (x)
	{
	case 1: y = 0; break;
	case 2: y = 31; break;
	case 3: y = 59; break;
	case 4: y = 90; break;
	case 5: y = 120; break;
	case 6: y = 151; break;
	case 7: y = 181; break;
	case 8: y = 212; break;
	case 9: y = 243; break;
	case 10:y = 273; break;
	case 11:y = 304; break;
	case 12:y = 334; break;
	default: printf("Invalid Inputnnnn"); exit(1);
	}
	return(y);
}
void testController() {
	ProductRepo* v = createRepo();
	Controller* c = createController(v);
	struct tm tm1, tm2;
	tm1.tm_year = 0;
	tm2.tm_year = 1;
	Product* p1 = createProduct("as", "dairy", 200, tm1);
	Product* p2 = createProduct("s", "dairy", 200, tm2);

	// add
	assert(addProductCtrl(c, "as", "dairy", 20, tm1) == 1);
	assert(addProductCtrl(c, "as", "dairy", 20, tm1) != 1);

	// delete
	assert(deleteCtrl(c, "as", "dairy") == 1);
	assert(deleteCtrl(c, "as", "dairy") == 0);

	//update
	addProduct(v, p1);
	addProduct(v, p2);

	assert(updateCtrl(c, "as","dairy",20, tm1, "saa", "dairy") == 0);
	assert(updateCtrl(c, "saa", "dairy", 20, tm2, "saa", "dairy") == 0);
	
	// search
//	assert(searchCtrl(c, "s") != NULL);
//	assert(searchCtrl(c, "s")->products->length == 2);
	
	destroyProduct(p1);
	destroyProduct(p2);
	destroyController(c);

}


int redo(Controller* c)
{
	if (isEmpty(c->redoStack))
	{
		return 0;
	}
	Operation* operation = pop(c->redoStack);
	c->canRecord = 0;
	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Product* product = getProduct(operation);
		addProductCtrl(c, product->name, product->type, product->quantity, product->expirationDate);
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		Product* product = getProduct(operation);
		deleteCtrl(c, product->name, product->type);

	} 
	else if (strcmp(getOperationType(operation), "addQ") == 0) {
		Product* product = getProduct(operation);
		addProductCtrl(c, product->name, product->type, product->quantity, product->expirationDate);
	}
	else if (strcmp(getOperationType(operation), "update") == 0) {
		Operation * operationNew = pop(c->redoStack);
		Product *pOld = getProduct(operationNew);
		Product *pNew = getProduct(operation);
		updateCtrl(c, pNew->name, pNew->type, pNew->quantity, pNew->expirationDate, pOld->name, pOld->type);
		destroyOperation(operationNew);
		destroyProduct(pNew);
		//destroyProduct(pOld);
	}

	// the operation must be destroyed
	destroyOperation(operation);
	c->canRecord = 1;
	return 1;

}