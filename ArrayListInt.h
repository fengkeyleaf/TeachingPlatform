#ifndef ARRAYLISTINT_H_INCLUDED
#define ARRAYLISTINT_H_INCLUDED

/*
 * @author: Xiaoyu Tongyang or you can call me sora for short
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct ArrayListInt {
    int* data;
    size_t index;
    size_t capacity;
} ArrayListInt;

// constructor operations
ArrayListInt* createArrayListInt( const int* data, size_t len );
ArrayListInt* createArrayListIntDefaultCapacity();
ArrayListInt* createArrayListIntWithCapacity( size_t capacity );

// add operations
void appendArrayListInt( ArrayListInt*, int );
void insertArrayListInt( ArrayListInt*, int , int );

void extendArrayInt( ArrayListInt* aArrayListInt, const int* data );
void copyIntArray( int* des, const int* src, size_t start, size_t ending );

// delete operations
int deleteLastArrayListInt( ArrayListInt* aArrayListInt );
int deleteIndexArrayListInt( ArrayListInt* aArrayListInt, size_t index );

// obtain operations
int getArrayListInt( ArrayListInt* aArrayListInt, int index );
int isEmptyArrayListInt( ArrayListInt* aArrayListInt );

int checkIfIndexValid( ArrayListInt* aArrayListInt, int index );
void reorangeArrayListInt( ArrayListInt* aArrayListInt );
void shrinkArrayInt( ArrayListInt* aArrayListInt, const int* data );

// find operations
int linearSearchArrayListInt( ArrayListInt* aArrayListInt, int target );

// sort operations
// selection sort
void selectionSortArrayListInt( ArrayListInt* aArrayListInt, int ascending );
void swapTwoInt( ArrayListInt* aArrayListInt, int i, int j );
void reverseArrayListInt( ArrayListInt* aArrayListInt );

// quickSort
void quickSortArrayListInt( ArrayListInt* aArrayListInt, int ascending );
void myQuickSortArrayListInt(  ArrayListInt* aArrayListInt, int start, int ending );
int partitionArrayListInt( ArrayListInt* aArrayListInt, int start, int ending );

// print
void printArrayListInt( ArrayListInt* aArrayListInt );

// test
void testArrayListInt();

#endif // ARRAYLISTINT_H_INCLUDED
