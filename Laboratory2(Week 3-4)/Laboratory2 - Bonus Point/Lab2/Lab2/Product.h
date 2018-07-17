#pragma once
#include <time.h>
// our product
typedef struct {
	char* name;
	char* type;
	double quantity;
	struct tm expirationDate;
} Product;

/*
	"Constructor", "destructor", "Copy constructor"
*/
Product* createProduct(char* name, char* type, double quantity, struct tm expirationDate);
void destroyProduct(Product* product);
Product* copyProduct(Product* product);

// getters
char* getName(Product* product);
char* getType(Product* product);
double getQuantity(Product* product);
struct tm getExpirationDate(Product* product);

void toString(Product* product, char* productStr);

int isValidType(char* type);

