#pragma once
#include "Repo.h"
#include <time.h>
#include "OperationStack.h"

typedef int(*SearchFilter)(Product* p1, Product* p2); 
typedef int(*Filter)(double p1, Product* p2);

typedef struct
{
	ProductRepo* repo;
	OperationsStack* undoStack, *redoStack;
	int canRecord;
} Controller;

Controller* createController(ProductRepo* r);

void destroyController(Controller* c);

/// <summary>
/// Adds a product to the repository of products.
/// </summary>
/// <param name="c">Pointer to theController.</param>
/// <param name = "name">A string, the name of the product.</param>
/// <param name = "type">A string, the product's type.</param>
/// <param name = "quantity">Double, the quantity</param>
/// <returns>1 - if the product was sucessfully added; 0 - if the product could not be added, as another product with the same symbol already exists.</returns>
int addProductCtrl(Controller* c, char* name, char* type, double quantity, struct tm s);

ProductRepo* getRepo(Controller* c);

/*
	Deletes a product by its name and type
	input: - c - pointer to the controller
		   - name - array of chars - the name of the product
		   - type - array of chars - the type of the product
	Output: 1 - If a product with the given name exists in the repository, it is deleted, 0 - if there are errors.

*/
int deleteCtrl(Controller* c, char* name, char* type);


/*
Update an product from the repository
Input:	c - pointer to the controller;
	- name - array of chars - the name of the product
	- type - array of chars - the type of the product
	- quantity - double - the quantity
	- s - tm struct - the expiration date
	- oldName - array of chars - the old name
	- oldType - array of chars - the old type
output: 1 - if updated with success, 0 otherwise

*/
int updateCtrl(Controller* c, char* name, char* type, double quantity, struct tm s, char* oldName, char* oldType);

/*
	It searches for all the products that contain the search word in its name, and returns an auxiliary repo with its element in the descending order of the quantity 
	Input:	c - pointer to the controller;
		- search - array of chars - the searh word
	Output: ProductRepo* - contains the searched products with its element in the descending order of the quantity 
*/
ProductRepo* searchCtrl(Controller* c, char* search, SearchFilter s);

/*
Sorting criteria for products -> like a lambda/predicate function used for sorting
Compares products by their quantity
Input:
auxRepo - ProductRepo* (no more needed but, too lazy to refactor now :)) )
p1 - Product* - first product
p2 - Product* - second product
Output:
1 - if p1.quantity < p2.quantity
0 - otherwise
*/

int sortByQuantity(ProductRepo* auxRepo, Product* p1, Product* p2);

/*
Descending sorting criteria for products -> like a lambda/predicate function used for sorting
Compares products by their quantity
Input:
auxRepo - ProductRepo* (no more needed but, too lazy to refactor now :)) )
p1 - Product* - first product
p2 - Product* - second product
Output:
1 - if p1.quantity > p2.quantity
0 - otherwise
*/
int sortByQuantityDesc(ProductRepo* auxRepo, Product* p1, Product* p2);

/*
Input: c - pointer to the controller
sorter - the sorting criteria ("lambda" function)
Output: ProductRepo* - that contains all the objects sorted by the given criteria
*/
ProductRepo* sort(Controller* c, SearchFilter sorter);

/*

Sorting criteria for products -> like a lambda/predicate function used for sorting
Compares products by their name (sorts them alphabetically
Input:
auxRepo - ProductRepo* (no more needed but, too lazy to refactor now :)) )
p1 - Product* - first product
p2 - Product* - second product
Output:
1 - if p1.name < p2.name
0 - otherwise
*/
int sortByName(ProductRepo* auxRepo, Product* p1, Product* p2);

/*
Descending sorting criteria for products -> like a lambda/predicate function used for sorting
Compares products by their quantity
Input:
auxRepo - ProductRepo* (no more needed but, too lazy to refactor now :)) )
p1 - Product* - first product
p2 - Product* - second product
Output:
1 - if p1.quantity > p2.quantity
0 - otherwise
*/
int sortByNameDesc(ProductRepo* auxRepo, Product* p1, Product* p2);

/*
Gets all products by their type
Input:
c - pointer to the Controller
type - array of characters - the type by which we filter
Output:
ProductRepo* - that contains all the objects with the given type

*/
ProductRepo* getProductByType(Controller* c, char* type);

/*
Filter criteria -> like a "lambda" function
Returns if the product expires in a number of days smaller than the given one
Input:
p - ProductRepo* - pointer to the repository
days - number of days
tm - time struct from C
Output
ProductRepo* - that contains all the objects with the wanted requirement

*/
ProductRepo* filterByDate(ProductRepo* p, int days, struct tm* s);

/*
Filters the products by their quantity, using a given filter criteria
Input:
c - pointer to the controller
quantity - the quantity with which we compare
filter - filter criteria -> "lambda" function
*/
ProductRepo* filterByQuantity(Controller* c, double quantity, Filter filter);

/*
"Undoes" the last action
Input:
c - pointer to the controller
Output:
1 - if the undo was successful
0 - otherwise
*/
int undo(Controller* c);

/*
"Redoes" the last action
Input:
c - pointer to the controller
Output:
1 - if the redo was successful
0 - otherwise
*/
int redo(Controller* c);

/*
Filter criteria -> like a "lambda" function
Compares product's quantity with a given quantity
Input:
p - ProductRepo* - pointer to the repository
quantity - int - the minimum quantity
Output:
1 -  if the quantity is bigger
0 - otherwise
*/
int filterQuantityBigger(double quantity, Product* p);

/*
Filter criteria -> like a "lambda" function
Compares product's quantity with a given quantity
Input:
p - ProductRepo* - pointer to the repository
quantity - int - the maximum quantity
Output:
1 -  if the quantity is smaller
0 - otherwise
*/
int filterQuantitySmaller(double quantity, Product* p);