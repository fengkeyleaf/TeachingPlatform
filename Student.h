#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Double.h"
#include "String.h"
#include "ArrayListGeneric.h"

#define EPSILON 0.000001

// Structure Definition Grade
typedef struct Grade {
    ArrayListGeneric* courses; // char**
    ArrayListGeneric* scores;  // double**
    ArrayListGeneric* credits; // double**
} Grade;

// Structure Definition Student
typedef struct Student {
    size_t ID;
    char* name;
    char* major;
    char* className;
    double weightedGPA;
    Grade myGrade;
} Student;

// function definition
Student* newStudentDefalut( size_t, char*, char*, char* );
Student* newStudent( size_t, char*, char*, char*, ArrayListGeneric*, ArrayListGeneric*, ArrayListGeneric* );

double calculateGrade( Grade* );
void toStringStudent( Student* );

// comparable
int compareToStudent(Student* , Student*);

// equals
int equalsStudent( Student*, Student* );

#endif // STUDENT_H_INCLUDED
