#pragma once
#pragma once
#include "Product.h"
#include "DynamicArray.h"
#include <string.h>

typedef struct
{
	Product* product;
	char* operationType;
} Operation;

// constructor, destructor, copy constructor
Operation* createOperation(Product* p, char* operationType);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* o);

// getters
char* getOperationType(Operation* o);
Product* getProduct(Operation* o);

// ---------------------------------------------------------------
typedef struct
{
	Operation* operations[100];
	int length;
} OperationsStack;
// constructor,destructor for our operation stack
OperationsStack* createStack();
void destroyStack(OperationsStack* s);
/*
Pushes the operation to the operation stack
*/
void push(OperationsStack* s, Operation* o);

Operation* pop(OperationsStack* s);
/*
Pops the last product repo from the stack and returns it
*/

//Self explanatory
int isEmpty(OperationsStack* s);
int isFull(OperationsStack* s);

void testsStack();