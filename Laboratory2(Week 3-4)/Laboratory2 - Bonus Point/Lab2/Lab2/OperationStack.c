#include "RepoStack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "Repo.h"
Operation* createOperation(Product* p, char* operationType)
{
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->product = copyProduct(p);

	if (operationType != NULL)
	{
		o->operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;

	return o;
}

void destroyOperation(Operation* o)
{
	if (o == NULL)
		return;

	// first destroy the product
	
	destroyProduct(o->product);
	// then the operationType
	free(o->operationType);
	// then free the operation
	free(o);
}

Operation* copyOperation(Operation * o)
{
	if (o == NULL)
		return NULL;

	Operation* newOp = createOperation(o->product, o->operationType);
	return newOp;
}

char* getOperationType(Operation* o)
{
	return o->operationType;
}

Product* getProduct(Operation* o)
{
	return o->product;
}

// ---------------------------------------------------------------

OperationsStack* createStack()
{
	OperationsStack* s = (OperationsStack*)malloc(sizeof(OperationsStack));
	s->length = 0;

	return s;
}

void destroyStack(OperationsStack* s)
{
	if (s == NULL)
		return;

	// first deallocate memory of operations (this is allocated when a new operation is pushed onto the stack)
	for (int i = 0; i < s->length; i++)
		destroyRepo(s->productRepo[i]);

	// then free the stack
	free(s);
}

void push(OperationsStack* s, ProductRepo* o)
{
	if (isFull(s))
		return;

	s->productRepo[s->length++] = copyProductRepo(o);	// copies of operations are added, such that the stask manages its own operations
}

ProductRepo* pop(OperationsStack* s)
{
	if (isEmpty(s))
		return NULL;
	s->length--;
	if (s->length == -1)
		return createRepo();
	return s->productRepo[s->length];
}

int isEmpty(OperationsStack* s)
{
	return (s->length == 0);
}

int isFull(OperationsStack* s)
{
	return s->length == 100;
}


// Tests
void testsStack()
{
	OperationsStack* s = createStack();
	struct tm tm1, tm2;
	tm1.tm_year = 0;
	tm2.tm_year = 1;
	Product* p1 = createProduct("1", "dairy", 200, tm1);
	Product* p2 = createProduct("2", "dairy", 200, tm2);
	Product* p3 = createProduct("3", "dairy", 200, tm2);
	
	ProductRepo* r = createRepo();
	addProduct(r, p1);
	push(s, r);
	addProduct(r, p2);
	push(s, r);
	addProduct(r, p3);
	push(s, r);
	// the products may be destroyed, as the operations contain copies of these products


	// the operations may be destroyed, as the stack contains copies of these operations
	destroyProduct(p1);
	destroyProduct(p2);
	destroyProduct(p3);

	assert(strcmp("3", getName(getProductOnPos(pop(s), 2)))==0);
	assert(s->length == 2);
	//assert(stcmp(getName(getProductOnPos(pop(s), 2)),"3"));
	//assert(isFull(s) == 0);
	//assert(isEmpty(s) == 0);
	//Operation* o = pop(s);
	//assert(strcmp(o->operationType, "remove") == 0);
	//// after each pop, the operations must be destroyed
	//destroyOperation(o);

	//o = pop(s);
	//assert(strcmp(o->operationType, "add") == 0);
	//destroyOperation(o);

	//o = pop(s);
	//assert(strcmp(o->operationType, "add") == 0);
	//destroyOperation(o);

	//assert(isEmpty(s) == 1);

	//// destroy the stack
	destroyStack(s);
}