#pragma once
#include "Product.h"
#include "DynamicArray.h"
#include <string.h>
#include "Repo.h"

// we define our operation
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
	ProductRepo* productRepo[100];
	int length;
} OperationsStack;

// constructor,destructor for our operation stack
OperationsStack* createStack();
void destroyStack(OperationsStack* s);
/*
	Pushes the product repo to the operation stack
*/
void push(OperationsStack* s, ProductRepo* o);
/*
	Pops the last product repo from the stack and returns it
*/
ProductRepo* pop(OperationsStack* s);

void testsStack();