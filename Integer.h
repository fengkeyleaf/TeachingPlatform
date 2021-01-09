#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Integer {
    int num;
} Integer;

// print - toString
void printInteger( Integer** Integers, size_t len );
void toStringInteger( Integer* Integer );

// basic algebra
Integer* additionInteger( Integer*, Integer* );
Integer* substractionInteger( Integer*, Integer* );
Integer* multificationInteger( Integer*, Integer* );
Integer* divisionInteger( Integer*, Integer* );

// comparable
int compareToInteger(Integer* , Integer*);

#endif // INTEGER_H_INCLUDED
