#include "Integer.h"

// constructors

/*
 * constructs an Integer with value num
 *
 */

Integer* newInteger( int num ) {
    Integer* aInteger = (Integer*) malloc( sizeof(Integer) );
    aInteger->num = num;
    return aInteger;
}

// basic algebra
Integer* additionInteger( Integer* num1, Integer* num2 ) {
    num1->num += num2->num;
    return num1;
}

Integer* substractionInteger( Integer* num1, Integer* num2 ) {
    num1->num -= num2->num;
    return num1;
}

Integer* multificationInteger( Integer* num1, Integer* num2 ) {
    num1->num *= num2->num;
    return num1;
}

Integer* divisionInteger( Integer* num1, Integer* num2 ) {
    num1->num /= num2->num;
    return num1;
}


// comparable

/*
 * comparable, equivalent to comparable<T> in Java
 * This interface imposes a total ordering on the objects of each class that implements it.
 * This ordering is referred to as the class's natural ordering,
 * and the class's compareTo method is referred to as its natural comparison method.
 *
 */

int compareToInteger(Integer* num1, Integer* num2) {
    return num1->num - num2->num;
}


// equals

/*
 * comparable, equivalent to comparable<T> in Java
 * This interface imposes a total ordering on the objects of each class that implements it.
 * This ordering is referred to as the class's natural ordering,
 * and the class's compareTo method is referred to as its natural comparison method.
 *
 */

int equalsInteger( Integer* num1, Integer* num2 ) {
    return compareToInteger( num1, num2 ) == 0;
}


// print

/*
 * print an array containing Integers
 *
 */

void printInteger( Integer** Integers, size_t len ) {
    printf("[ ");
    for (int i = 0; i < len; i++)
        printf("%d ", Integers[i]->num );
    printf("] | size: %d\n", len );
}


// toString

/*
 * toString() in Java
 * Returns a string representation of the object.
 */

void toStringInteger( Integer* Integer ) {
    printf("%d ", Integer->num );
}
