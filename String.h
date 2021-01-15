#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

/*
 * @author: Xiaoyu Tongyang or you can call me sora for short
 */

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
