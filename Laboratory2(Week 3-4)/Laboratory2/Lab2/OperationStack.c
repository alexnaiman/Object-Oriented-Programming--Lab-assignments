#include "OperationStack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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
		destroyOperation(s->operations[i]);

	// then free the stack
	free(s);
}

void push(OperationsStack* s, Operation* o)
{
	if (isFull(s))
		return;

	s->operations[s->length++] = copyOperation(o);	// copies of operations are added, such that the stask manages its own operations
}

Operation* pop(OperationsStack* s)
{
	if (isEmpty(s))
		return NULL;
	s->length--;
	return s->operations[s->length];
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
	Product* p1 = createProduct("as", "dairy", 200, tm1);
	Product* p2 = createProduct("s", "dairy", 200, tm2);
	Operation* o1 = createOperation(p1, "add");
	Operation* o2 = createOperation(p2, "add");
	Operation* o3 = createOperation(p1, "remove");

	// the products may be destroyed, as the operations contain copies of these products
	destroyProduct(p1);
	destroyProduct(p2);

	push(s, o1);
	push(s, o2);
	push(s, o3);

	// the operations may be destroyed, as the stack contains copies of these operations
	destroyOperation(o1);
	destroyOperation(o2);
	destroyOperation(o3);

	assert(isFull(s) == 0);
	assert(isEmpty(s) == 0);
	Operation* o = pop(s);
	assert(strcmp(o->operationType, "remove") == 0);
	// after each pop, the operations must be destroyed
	destroyOperation(o);

	o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	assert(isEmpty(s) == 1);

	// destroy the stack
	destroyStack(s);
}