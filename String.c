#include "String.h"

// constructor

/*
 * constructs an String with a char array
 *
 */

String* newString( char* contend ) {
    String* aString = (String*) malloc( sizeof(String) );
    aString->characters = contend;
    return aString;
}

// toString

/*
 * toString() in Java
 * Returns a string representation of the object.
 */

void toStringString( String* aString ) {
    printf("%s ", aString->characters );
}
