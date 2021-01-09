#ifndef ARRAYLISTGENERIC_H_INCLUDED
#define ARRAYLISTGENERIC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Integer.h"

#define TRUE 1
#define FALSE 0

typedef struct ArrayListGeneric {
    void** data;
    size_t index;
    size_t capacity;
} ArrayListGeneric;

// constructor operations
ArrayListGeneric* createArrayListGeneric( void* const * data, size_t len );
ArrayListGeneric* createArrayListGenericDefaultCapacity();
ArrayListGeneric* createArrayListGenericWithCapacity( size_t capacity );

// add operations
void appendArrayListGeneric ( ArrayListGeneric* aArrayListGeneric, void* element );
void insertArrayListGeneric( ArrayListGeneric*, void* element , int );

void extendArrayListGeneric( ArrayListGeneric* aArrayListGeneric, void* const * data );
void copyArrayListGeneric( void** des, void* const * src, size_t start, size_t ending );

// delete operations
void* deleteLastArrayListGeneric( ArrayListGeneric* aArrayListGeneric );
void* deleteIndexArrayListGeneric( ArrayListGeneric* aArrayListGeneric, int index );

// obtain operations
void* getArrayListGeneric ( ArrayListGeneric* aArrayListGeneric, int index );

int isEmptyArrayListGeneric( ArrayListGeneric* aArrayListGeneric );
int checkIfIndexValidGeneric( ArrayListGeneric* aArrayListGeneric, int index );
void reorangeArrayListGeneric( ArrayListGeneric* aArrayListGeneric );
void shrinkArrayListGeneric( ArrayListGeneric* aArrayListGeneric, void* const * data );

// find operations
int linearSearchGeneric( ArrayListGeneric* aArrayListGeneric, void* target, int (*compareToGeneric)(void*, void*) );

// sort operations
// selection sort
void selectionSortGeneric( ArrayListGeneric* aArrayListGeneric, int ascending, int (*compareToGeneric)(void*, void*) );
void swapTwoGerneric( ArrayListGeneric* aArrayListGeneric, int i, int j );
void reverseGerneric( ArrayListGeneric* aArrayListGeneric );

// quickSort
void quickSortGeneric( ArrayListGeneric* aArrayListGeneric, int ascending, int (*compareToGeneric)(void*, void*) );
void myQuickSortGeneric(  ArrayListGeneric* aArrayListGeneric, int start, int ending, int (*compareToGeneric)(void*, void*) );
int partitionGeneric( ArrayListGeneric* aArrayListGeneric, int start, int ending, int (*compareToGeneric)(void*, void*) );

// generic function pointer to compareTo
typedef int (*compareToPtr)(void*, void*);

// toString
void toStringGeneric( ArrayListGeneric* aArrayListGeneric, void (*toStringInstance)(void*) );

// test
void testArrayGenericWithInteger();

#endif // ARRAYLISTGENERIC_H_INCLUDED
