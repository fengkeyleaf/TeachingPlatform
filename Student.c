/*
 * @author: Xiaoyu Tongyang or you can call me sora for short
 */

#include "Student.h"

/*
 * constructor to create an instance of a Student with basic information
 *
 */

Student* newStudentDefalut( size_t ID, char* name, char* major, char* className ) {
    Student* aStudent = ( Student* ) malloc( sizeof (Student) );
    aStudent->ID = ID;
    aStudent->name = name;
    aStudent->major = major;
    aStudent->className = className;
    aStudent->weightedGPA = -1.0;
    return aStudent;
}

/*
 * constructor to create an instance of a Student
 * with basic information plus courses, scores and credits
 *
 */

Student* newStudent( size_t ID, char* name, char* major, char* className,
                    ArrayListGeneric* courses, ArrayListGeneric* scores,
                    ArrayListGeneric* credits) {
    Student* aStudent = newStudentDefalut( ID, name, major, className );
    aStudent->myGrade.courses = courses;
    aStudent->myGrade.scores = scores;
    aStudent->myGrade.credits = credits;

    aStudent->weightedGPA = calculateGrade( &aStudent->myGrade );
    return aStudent;
}


/*
 * calculate grades for a student
 */

double calculateGrade( Grade* aGrade ) {
    double totalScores = 0.0;
    double totalCreadits = 0.0;
    for ( int i = 0; i < aGrade->courses->index; i++ ) {
        totalScores += ( (Double*) aGrade->scores->data[i] )->num
                        * ( (Double*) aGrade->credits->data[i] )->num;
        totalCreadits += ( (Double*) aGrade->credits->data[i] )->num;
    }

    return totalScores / totalCreadits;
}

/*
 * toString() in Java
 * Returns a string representation of the object.
 */

void toStringStudent( Student* aStudent ) {
    printf("ID: %lu | Name: %s | Major: %s | className: %s | weightedGPA: %f\n",
           aStudent->ID, aStudent->name, aStudent->major,
           aStudent->className, aStudent->weightedGPA);
    printf("Courses: ");
    toStringGeneric( aStudent->myGrade.courses, toStringString );
    printf("Scores: ");
    toStringGeneric( aStudent->myGrade.scores, toStringDouble );
    printf("Credits: ");
    toStringGeneric( aStudent->myGrade.credits, toStringDouble );

}


// comparable

/*
 * comparable, equivalent to comparable<T> in Java
 * This interface imposes a total ordering on the objects of each class that implements it.
 * This ordering is referred to as the class's natural ordering,
 * and the class's compareTo method is referred to as its natural comparison method.
 *
 */

int compareToStudent(Student* aStudent1 , Student* aStudent2) {
    Double* GPA1 = newDoulbe( aStudent1->weightedGPA );
    Double* GPA2 = newDoulbe( aStudent2->weightedGPA );
    int result = compareToDouble( GPA1, GPA2 );
    free( GPA1 );
    free( GPA2 );
    return result;
}


// equals

/*
 * equals, equivalent to equals​(Object obj)	in Java
 * Indicates whether some other object is "equal to" this one.
 */

int equalsStudent( Student* aStudent1, Student* aStudent2 ) {
    return aStudent1->ID == aStudent2->ID;
}
