#include "Product.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

Product* createProduct(char* name, char* type, double quantity, struct tm expirationDate) {
	// allocate memory for the product
	Product* p = (Product*)malloc(sizeof(Product));
	if (p == NULL)
		return NULL;
	// allocate memory for the product's name
	p->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	// copy the given name in the allocated area of memory
	strcpy(p->name, name);
	// allocate memory for the product's type
	p->type = (char*)malloc(sizeof(char)* (strlen(type) + 1));
	// copy the given type in the allocated area of memory
	strcpy(p->type, type);
	
	p->quantity = quantity;
	
	p->expirationDate = expirationDate;

	return p;
}


void destroyProduct(Product* p) {
	if (p == NULL)
		return;
	// free the memory which was allocated for the component fields
	free(p->name);
	free(p->type);
	// free the memory which was allocated for the product structure
	free(p);
}

Product* copyProduct(Product* p) {
	if (p == NULL)
		return NULL;
	Product* newProduct = createProduct(getName(p), getType(p), getQuantity(p), getExpirationDate(p));
	return newProduct;
}

char* getName(Product* p) {
	return p->name;
}

char* getType(Product* p) {
	return p->type;
}

double getQuantity(Product * p) {
	return p->quantity;
}

struct tm getExpirationDate(Product* p) {
	return p->expirationDate;
}

void toString(Product* product, char* productStr) {

	sprintf(productStr,"The product %s of type %s has a quantity of %lf - expiration date: %d-%d-%d", getName(product), getType(product), getQuantity(product), getExpirationDate(product).tm_year, getExpirationDate(product).tm_mon, getExpirationDate(product).tm_mday);
}

char TYPES[4][10] = {
	"dairy",
	"sweets",
	"meat",
	"fruit"
};

int isValidType(char* type) {
	for (int i = 0; i < 4; i++)
		if (strcmp(type, TYPES[i])==0)
			return 1;
	return 0;
}