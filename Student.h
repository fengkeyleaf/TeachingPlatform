#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

/*
 * @author: Xiaoyu Tongyang or you can call me sora for short
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Double.h"
#include "String.h"
#include "ArrayListGeneric.h"

#define EPSILON 0.000001

// class Definition Grade
typedef struct Grade {
    ArrayListGeneric* courses; // char**
    ArrayListGeneric* scores;  // double**
    ArrayListGeneric* credits; // double**
} Grade;

// class Definition Student
typedef struct Student {
    size_t ID;
    char* name;
    char* major;
    char* className;
    double weightedGPA;
    Grade myGrade;
} Student;

// constructors
Student* newStudentDefalut( size_t, char*, char*, char* );
Student* newStudent( size_t, char*, char*, char*, ArrayListGeneric*, ArrayListGeneric*, ArrayListGeneric* );

double calculateGrade( Grade* );
void toStringStudent( Student* );

// comparable
int compareToStudent(Student* , Student*);

// equals
int equalsStudent( Student*, Student* );

#endif // STUDENT_H_INCLUDED
