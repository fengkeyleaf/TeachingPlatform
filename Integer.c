#include "Integer.h"


// print
void printInteger( Integer** Integers, size_t len ) {
    printf("[ ");
    for (int i = 0; i < len; i++)
        printf("%d ", Integers[i]->num );
    printf("] | size: %d\n", len );
}

void toStringInteger( Integer* Integer ) {
    printf("%d ", Integer->num );
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
int compareToInteger(Integer* num1, Integer* num2) {
    return num1->num - num2->num;
}
