#pragma once
#define CAPACITY 10

typedef void* TElem; // Generic element type
typedef void(*DestroyElemFunctionType)(void*); // pointer to a function that destroys the  element function 

typedef struct {
	TElem* elems;
	int length; // actual length of the array
	int capacity; // maximum capacity of the array
	DestroyElemFunctionType destroyElemFct;  // function pointer to the function responsible with deallocating the elements stored in the array

} DynamicArray;

/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the dynamic array.</param>
/// <param name="destroyEle	mFct">Function pointer, of type DestroyElemFunctionType. The function that deals with deallocating the elements of the array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArray*  createDynamicArray(int capacity, DestroyElemFunctionType destroyElemFct);

/// <summary>
/// Destroys the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array to be destoyed.</param>
/// <returns>A pointer the the created dynamic array.</returns>
void destroy(DynamicArray* arr);

/// <summary>
/// Adds a generic to the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="p">The planet to be added.</param>
void add(DynamicArray* arr, TElem t);

/// <summary>
/// Deletes an element from a given position in the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="pos">The position from which the element must be deleted. The position must be valid.</param>
void delete(DynamicArray* arr, int pos);


/// <summary>
/// Returns the length of the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
int getLength(DynamicArray* arr);

/// <summary>
/// Returns the element on a given position.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="pos">The position - must be a valid position.</param>
/// <returns>The element on the given position.</returns>
TElem get(DynamicArray* arr, int pos);

