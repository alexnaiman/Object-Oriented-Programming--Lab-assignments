#pragma once
#include <time.h>
typedef struct {
	char* name;
	char* type;
	double quantity;
	struct tm expirationDate;
} Product;

// constructor, destructor, copy constructor
Product* createProduct(char* name, char* type, double quantity, struct tm expirationDate);
void destroyProduct(Product* product);
Product* copyProduct(Product* product);
// getters and setters
char* getName(Product* product);
char* getType(Product* product);
double getQuantity(Product* product);
struct tm getExpirationDate(Product* product);

void toString(Product* product, char* productStr);

int isValidType(char* type);

