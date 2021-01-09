#ifndef DOUBLE_H_INCLUDED
#define DOUBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.000001

typedef struct Double {
    double num;
} Double;

// constructor
Double* newDoulbe( double );

// basic algebra
Double* additionDouble( Double*, Double* );
Double* substractionDouble( Double*, Double* );
Double* multificationDouble( Double*, Double* );
Double* divisionDouble( Double*, Double* );

// comparable
int compareToDouble(Double* , Double*);

// toString
//void printInteger( Integer** Integers, size_t len );
void toStringDouble( Double* aDouble );

#endif // DOUBLE_H_INCLUDED
