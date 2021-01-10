#ifndef DOUBLE_H_INCLUDED
#define DOUBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.000001

// class definition
typedef struct Double {
    double num;
} Double;

// constructors
Double* newDoulbe( double );

// basic algebra
Double* additionDouble( Double*, Double* );
Double* substractionDouble( Double*, Double* );
Double* multificationDouble( Double*, Double* );
Double* divisionDouble( Double*, Double* );

// comparable
int compareToDouble( Double* , Double* );

// equals
int equalsDouble( Double*, Double* );

// toString
void toStringDouble( Double* aDouble );

#endif // DOUBLE_H_INCLUDED
