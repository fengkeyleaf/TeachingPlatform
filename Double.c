#include "Double.h"

// constructor

/*
 * constructs an Double with value num
 *
 */

Double* newDoulbe( double num ) {
    Double* aDouble = (Double*) malloc( sizeof(Double) );
    aDouble->num = num;
    return aDouble;
}


// basic algebra

Double* additionDouble( Double* num1, Double* num2 ) {
    num1->num += num2->num;
    return num1;
}

Double* substractionDouble( Double* num1, Double* num2 ) {
    num1->num -= num2->num;
    return num1;
}

Double* multificationDouble( Double* num1, Double* num2 ) {
    num1->num *= num2->num;
    return num1;
}

Double* divisionDouble( Double* num1, Double* num2 ) {
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

int compareToDouble(Double* aDouble1 , Double* aDouble2) {
    if ( fabs( aDouble1->num - aDouble2->num ) <= EPSILON )
        return 0;
    else if ( aDouble1->num - aDouble2->num < 0.0 )
        return -1;

    return 1;
}


// equals

/*
 * comparable, equivalent to comparable<T> in Java
 * This interface imposes a total ordering on the objects of each class that implements it.
 * This ordering is referred to as the class's natural ordering,
 * and the class's compareTo method is referred to as its natural comparison method.
 *
 */

int equalsDouble( Double* num1, Double* num2 ) {
    return compareToDouble( num1, num2 ) == 0;
}


// toString

/*
 * toString() in Java
 * Returns a string representation of the object.
 */

void toStringDouble( Double* aDouble ) {
    printf("%f ", aDouble->num );
}
