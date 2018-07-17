#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
DynamicArray* createDynamicArray(int capacity, DestroyElemFunctionType destroyElemType) {
	DynamicArray* dynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	// make sure that the space was allocated
	if (dynamicArray == NULL)
		return NULL;

	dynamicArray->capacity = capacity;
	dynamicArray->length = 0;
	dynamicArray->destroyElemFct = destroyElemType;
	// allocate space for the elements
	dynamicArray->elems = NULL;
	dynamicArray->elems = (TElem*)malloc(capacity * sizeof(TElem));
	dynamicArray->elems[0] = NULL;
	if (dynamicArray->elems == NULL)
		return NULL;
	return dynamicArray;
}

void destroy(DynamicArray* arr) {
	if (arr == NULL)
		return;
	// deallocate each of the elements
	for (int i = 0; i < arr->length; i++) 
		arr->destroyElemFct(arr->elems[i]);

	// free the space allocated for the elements
	free(arr->elems);
	arr->elems = NULL;

	// free the space allocated for the dynamic array
	free(arr);
	arr = NULL;
}

int resize(DynamicArray* arr) {
	if (arr == NULL)
		return 0;
	arr->capacity *= 2;

	TElem* aux = (TElem*)malloc(arr->capacity * sizeof(TElem));
	if (aux == NULL)
		return -1;
	for (int i = 0; i < arr->length; i++) {
		aux[i] = arr->elems[i];
	}
	free(arr->elems);
	arr->elems = aux;

	return 0;
}

void add(DynamicArray* arr, TElem t) {
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;
	// resize the array, if necessary
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length++] = t;
}

void delete(DynamicArray* arr, int pos) {
	if (arr == NULL)
		return;

	if (arr->elems == NULL)
		return;

	if (pos < 0 || pos >= arr->length)
		return;
	arr->destroyElemFct(get(arr,pos));
	for (int i = pos; i < arr->length; i++)
		arr->elems[i] = arr->elems[i + 1];

	arr->length--;


}

int getLength(DynamicArray* arr) {
	if (arr == NULL)
		return -1;
	return arr->length;

}

TElem get(DynamicArray* arr, int pos) {
	return arr->elems[pos];
}
