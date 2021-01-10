#ifndef ARRAYLISTGENERIC_H_INCLUDED
#define ARRAYLISTGENERIC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Integer.h"

#define TRUE 1
#define FALSE 0

// class Definition
typedef struct ArrayListGeneric {
    void** data;
    size_t index;
    size_t capacity;
} ArrayListGeneric;

// constructor operations
ArrayListGeneric* newArrayListGeneric( void* const *, size_t );
ArrayListGeneric* newArrayListGenericDefaultCapacity();
ArrayListGeneric* newArrayListGenericWithCapacity( size_t );

// add operations
void appendArrayListGeneric ( ArrayListGeneric* , void* );
void insertArrayListGeneric( ArrayListGeneric*, void* , int );

void extendArrayListGeneric( ArrayListGeneric* , void* const * );
void copyArrayListGeneric( void**, void* const *, size_t, size_t );

// delete operations
void* deleteLastArrayListGeneric( ArrayListGeneric* );
void* deleteIndexArrayListGeneric( ArrayListGeneric*, int );

// obtain operations
void* getArrayListGeneric ( ArrayListGeneric*, int );

int isEmptyArrayListGeneric( ArrayListGeneric* );
int checkIfIndexValidGeneric( ArrayListGeneric*, int index );
void reorangeArrayListGeneric( ArrayListGeneric* );
void shrinkArrayListGeneric( ArrayListGeneric*, void* const * );

// find operations
int linearSearchGeneric( ArrayListGeneric*, void*, int (*compareToGeneric)(void*, void*) );

// sort operations
// selection sort
void selectionSortGeneric( ArrayListGeneric*, int, int (*compareToGeneric)(void*, void*) );
void swapTwoGerneric( ArrayListGeneric*, int i, int j );
void reverseGerneric( ArrayListGeneric* );

// quickSort
void quickSortGeneric( ArrayListGeneric*, int, int (*compareToGeneric)(void*, void*) );
void myQuickSortGeneric(  ArrayListGeneric*, int, int, int (*compareToGeneric)(void*, void*) );
int partitionGeneric( ArrayListGeneric*, int, int, int (*compareToGeneric)(void*, void*) );

// generic function pointer to compareTo
typedef int (*compareToPtr)(void*, void*);

// toString
void toStringGeneric( ArrayListGeneric*, void (*toStringInstance)(void*) );

// free
void freeArrayListGeneric(ArrayListGeneric* );

// test
void testArrayGenericWithInteger();

#endif // ARRAYLISTGENERIC_H_INCLUDED
