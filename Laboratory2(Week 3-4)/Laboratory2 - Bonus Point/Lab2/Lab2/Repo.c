#include "Repo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "UI.h"
ProductRepo* createRepo() {
	ProductRepo* v = (ProductRepo*)malloc(sizeof(ProductRepo));
	v->products = createDynamicArray(CAPACITY, &destroyProduct);
	
	return v;
}

ProductRepo* copyProductRepo(ProductRepo* p) {
	if (p == NULL)
		return NULL;
	ProductRepo* newProductRepo = createRepo();
	for (int i = 0; i < getRepoLength(p); i++) {
		Product* p2 = copyProduct(getProductOnPos(p, i));
		addProduct(newProductRepo, p2);
		destroyProduct(p2);
	}
	return newProductRepo;
}

void destroyRepo(ProductRepo* v) {
	if (v == NULL)
		return;

	destroy(v->products);
	free(v);
}

DynamicArray* findPosOfProduct(ProductRepo * v, char * name)
{
	DynamicArray* f = createDynamicArray(10, &destroyProduct);
	if (v == NULL)
		return NULL;

	for (int i = 0; i < getLength(v->products); i++)
	{
		Product* p = get(v->products, i);
		if (strcmp(p->name, name) == 0)
			add(f, p);
	}
	return f;
}

int findProductPos(ProductRepo* v, char* name, char* type) {
	int pos = 0;
	if (v == NULL)
		return -1;

	for (int i = 0; i < getLength(v->products); i++)
	{
		Product* p = get(v->products, i);
		if (strcmp(p->name, name) == 0 && strcmp(p->type, type) == 0)
			return i;
			
	}
	return -1;
}

Product* find(ProductRepo* v, char* name, char* type)
{
	if (v == NULL)
		return NULL;


	DynamicArray* pos = findPosOfProduct(v, name);
	for (int i = 0; i < pos->length; i++) {
		Product *p = get(pos, i);
		if (strcmp(type, p->type) == 0)
			return p;
	}
	return NULL;
}


int addProduct(ProductRepo* v, Product* p)
{
	if (v == NULL)
		return 0;
	int pf = findProductPos(v, p->name, p->type);
	if (pf != -1) {
		getProductOnPos(v, pf)->quantity += p->quantity;
		return -1;
	}
	Product* copy = copyProduct(p);
	add(v->products, copy);
	return 1;
}

int deleteProduct(ProductRepo* v, char* name, char* type)
{
	if (v == NULL)
		return 0;
	int pos = findProductPos(v, name, type);
	if (pos == -1)
		return 0;

	// destroy the product
	Product* p = get(v->products, pos);

	// delete the pointer from the dynamic array
	delete(v->products, pos);
	//destroyProduct(p);
	
	return 1;
}

int getRepoLength(ProductRepo* v)
{
	if (v == NULL)
		return -1;

	return getLength(v->products);
}

Product* getProductOnPos(ProductRepo* v, int pos)
{
	if (v == NULL)
		return NULL;

	if (pos < 0 || pos >= getLength(v->products))
		return NULL;

	return get(v->products, pos);
}

int updateProduct(ProductRepo* p, Product* prod, char* oldName, char* oldType) {
	int pos = findProductPos(p, oldName, oldType);
	if (pos == -1)
		return 0;
	pos = findProductPos(p, getName(p), getType(p));
	if (pos != -1)
		return 0;
	deleteProduct(p, oldName, oldType);
	addProduct(p, prod);
	return 1;
}


//  tests
void testRepo()
{
	ProductRepo* v = createRepo();

	struct tm tm1, tm2;
	tm1.tm_year = 0;
	tm2.tm_year = 1;
	Product* p1 = createProduct("as", "dairy", 200, tm1);
	addProduct(v, p1);
	// length
	assert(getRepoLength(v) == 1);
	
	//add
	assert(strcmp(getName(getProductOnPos(v, 0)), "as") == 0);

	Product* p2 = createProduct("s", "dairy", 200, tm2);
	assert(addProduct(v, p2) == 1);
	assert(getRepoLength(v) == 2); 
	assert(addProduct(v, p2) == -1);
	// find //TODO memory leaks
	Product* ps = find(v, "as", "dairy");
	assert(ps->name != NULL);
	destroyProduct(ps);
	//assert(find(v, "as", "dairy") != p1);

	// delete
	//assert(deleteProduct(v, "as", "dairy") == 1);
	//assert(deleteProduct(v, "as", "dairy") == 0);

	//update
	addProduct(v, p1);
	addProduct(v, p2);

	assert(updateProduct(v, p2, "saa", "dairy") == 0);
	assert(updateProduct(v, p1, "saa", "dairy") == 0);
	assert(updateProduct(v, p1, "saa", "dairy") == 0);
	
	// destroy the test repository
	destroyRepo(v);

	// now the memory allocated for the products must be freed
	destroyProduct(p1);
	destroyProduct(p2);
}

void testsProductRepo() {
	testRepo();
}