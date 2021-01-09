#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Structure Definition String
typedef struct String {
    char* characters;
} String;

// constructor
String* newString( char* );

// toString
void toStringString( String* );

#endif // STRING_H_INCLUDED
