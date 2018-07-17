#pragma once
#include "DynamicArray.h"
#include "Product.h"

typedef struct
{
	DynamicArray* products;
} ProductRepo;


/// <summary>
/// Creates a ProductRepo.
/// </summary>
ProductRepo* createRepo();

/// <summary>
/// Destroys a given product repository. The memory is freed.
/// </summary>
void destroyRepo(ProductRepo* p);

/// <summary>
/// Finds the product with the given name.
/// </summary>
/// <param name="v">Pointer to the ProductRepo.</param>
/// <param name = "name">A string, the name to search for.</param>
/// <returns>The pointer to the product with the given name, or null, if such a Product does not exist.</returns>
Product* find(ProductRepo* v, char* name, char* type);


/*
	Adds a product to the repository of products.
	Input:	- v - pointer to the ProductRepo
			- p - product
	Output: 1 - if the product was sucessfully added
			0 - if the product could not be added, as another product with the same symbol already exists in the ProductRepo.
*/
int addProduct(ProductRepo* v, Product* p);

/*
Deletes the product with the given name from the repository.
	Input:  - v - pointer to the ProductRepo
			- name - a string, the name which identifies the product to be deleted.
	Output: 1 - If a product with the given name exists in the repository, it is deleted, 0 - if there are errors.
*/
int deleteProduct(ProductRepo* v, char* name, char* type);

/*
Returns the length of the reposiory
	Input: - v - pointer to the ProductRepo
	Output: Length of the dynamic list of the repository
*/
int getRepoLength(ProductRepo* v);


/*
Returns the product on the given position in the product vector.
Input:	v - pointer to the product repository;
pos - integer, the position;
Output: the product on the given potision, or an "empty" product.
*/
Product* getProductOnPos(ProductRepo* v, int pos);

void testsProductRepo();

/*
	Update an product from the repository
	Input:	v - pointer to the product repository;
			prod - the updated product
			oldName - array of chars - the old name
			oldType - array of chars - the old type
	output: 1 - if updated with success, 0 otherwise

*/
int updateProduct(ProductRepo* p, Product* prod, char* oldName, char* oldType);


