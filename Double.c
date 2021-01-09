#include "Double.h"

// constructor
Double* newDoulbe( double num ) {
    Double* aDouble = (Double*) malloc( sizeof(Double) );
    aDouble->num = num;
    return aDouble;
}

// comparable
int compareToDouble(Double* aDouble1 , Double* aDouble2) {
    if ( fabs( aDouble1->num - aDouble2->num ) <= EPSILON )
        return 0;
    else if ( aDouble1->num - aDouble2->num < 0.0 )
        return -1;

    return 1;
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

// toString
void toStringDouble( Double* aDouble ) {
    printf("%f ", aDouble->num );
}
