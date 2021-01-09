#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "predefine.h"
#include "ArrayListInt.h"
#include "ArrayListGeneric.h"
#include "Integer.h"
#include "Double.h"
#include "String.h"
#include "Student.h"

ArrayListGeneric* generateStudents() {
    ArrayListGeneric* students = createArrayListIntDefaultCapacity();

    // free
    Double* scoresArray1[] = { newDoulbe( 88.0 ), newDoulbe( 98.0 ), newDoulbe( 82.0 ), newDoulbe( 85.0 ), newDoulbe( 90.0 ) };
    ArrayListGeneric* scores1 = createArrayListGeneric( (void* const *) scoresArray1, 5 );
    toStringGeneric( scores1, toStringDouble );
    // free
    String* coursesChars[] = { newString("Chinese"), newString("Math"), newString("English"),
                                newString("Information"), newString("Sports") };
    ArrayListGeneric* courses = createArrayListGeneric( (void* const *) coursesChars, 5 );
    toStringGeneric( courses, toStringString );

    // free
    Double* creditsArray[] = { newDoulbe( 6.0 ), newDoulbe( 6.0 ), newDoulbe( 6.0 ), newDoulbe( 3.0 ), newDoulbe( 1.0 ) };
    ArrayListGeneric* credits = createArrayListGeneric( (void* const *) creditsArray, 5 );
    toStringGeneric( credits, toStringDouble );

    printf("\n");
    Student* aStudent1 = newStudent( 1, "Qian Meibao", "Computer", "A-1", courses, scores1, credits );
    toStringStudent( aStudent1 );
    appendArrayListGeneric( students, aStudent1 );

    printf("\n");
    Double* scoresArray2[] = { newDoulbe( 100.0 ), newDoulbe( 98.0 ), newDoulbe( 100.0 ), newDoulbe( 97.0 ), newDoulbe( 87.0 ) };
    ArrayListGeneric* scores2 = createArrayListGeneric( (void* const *) scoresArray2, 5 );
    Student* aStudent2 = newStudent( 2, "Zhang Pinggudang", "Computer", "A-1", courses, scores2, credits );
    appendArrayListGeneric( students, aStudent2 );

    Double* scoresArray3[] = { newDoulbe( 89.0 ), newDoulbe( 87.0 ), newDoulbe( 87.0 ), newDoulbe( 85.0 ), newDoulbe( 70.0 ) };
    ArrayListGeneric* scores3 = createArrayListGeneric( (void* const *) scoresArray3, 5 );
    Student* aStudent3 = newStudent( 3, "Xu Dongming", "Computer", "A-1", courses, scores3, credits );
    appendArrayListGeneric( students, aStudent3 );

    toStringGeneric( students, toStringStudent );
    return students;
}

int main()
{
    // Question 1 & 2
    printf("Question 1 & 2--------------->\n");
    ArrayListGeneric* students = generateStudents();
    Student* aStudent1 = getArrayListGeneric( students, 0 );

    // Question 3
    printf("\nQuestion 3--------------->\n");
    printf( "find aStudent1(ID -> %d): %s\n", 1, (
            ( linearSearchGeneric( students, aStudent1, equalsStudent ) > -1 ) ? "true" : "false" ) );

    Student* aStudent4 = newStudentDefalut( 4, "himea", "Computer", "A-1" );
    printf( "find aStudent1(ID -> %d): %s\n", 4, (
            ( linearSearchGeneric( students, aStudent4, equalsStudent ) > -1 ) ? "true" : "false" ) );

    // Question 4
    printf("\nQuestion 4--------------->\n");
    selectionSortGeneric( students, TRUE, compareToStudent );
    toStringGeneric( students, toStringStudent );

    // Question 5
    printf("\nQuestion 5--------------->\n");
    quickSortGeneric( students, FALSE, compareToStudent );
    toStringGeneric( students, toStringStudent );

    return 0;
}
