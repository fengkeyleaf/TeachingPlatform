#include "String.h"

// constructor
String* newString( char* contend ) {
    String* aString = (String*) malloc( sizeof(String) );
    aString->characters = contend;
    return aString;
}

// toString
void toStringString( String* aString ) {
    printf("%s ", aString->characters );
}
