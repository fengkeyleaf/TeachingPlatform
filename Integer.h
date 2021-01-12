#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

/*
 * @author: Xiaoyu Tongyang or you can call me sora for short
 */

#include <stdio.h>
#include <stdlib.h>

// class Definition
typedef struct Integer {
    int num;
} Integer;

// constructors
Integer* newInteger( int );

// basic algebra
Integer* additionInteger( Integer*, Integer* );
Integer* substractionInteger( Integer*, Integer* );
Integer* multificationInteger( Integer*, Integer* );
Integer* divisionInteger( Integer*, Integer* );

// comparable
int compareToInteger(Integer* , Integer*);

// equals
int equalsInteger( Integer*, Integer* );

// print
void printInteger( Integer** , size_t );

// toString
void toStringInteger( Integer* );

#endif // INTEGER_H_INCLUDED
