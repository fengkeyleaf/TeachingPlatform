#include "Student.h"

Student* newStudentDefalut( size_t ID, char* name, char* major, char* className ) {
    Student* aStudent = ( Student* ) malloc( sizeof (Student) );
    aStudent->ID = ID;
    aStudent->name = name;
    aStudent->major = major;
    aStudent->className = className;
    aStudent->weightedGPA = -1.0;
    return aStudent;
}

Student* newStudent( size_t ID, char* name, char* major, char* className,
                    ArrayListGeneric* courses, ArrayListGeneric* scores, ArrayListGeneric* credits) {
    Student* aStudent = ( Student* ) malloc( sizeof (Student) );
    aStudent->ID = ID;
    aStudent->name = name;
    aStudent->major = major;
    aStudent->className = className;
    aStudent->weightedGPA = -1.0;

    aStudent->myGrade.courses = courses;
    aStudent->myGrade.scores = scores;
    aStudent->myGrade.credits = credits;

    aStudent->weightedGPA = calculateGrade( &aStudent->myGrade );
    return aStudent;
}

double calculateGrade( Grade* aGrade ) {
    double totalScores = 0.0;
    double totalCreadits = 0.0;
    for ( int i = 0; i < aGrade->courses->index; i++ ) {
        totalScores += ( (Double*) aGrade->scores->data[i] )->num * ( (Double*) aGrade->credits->data[i] )->num;
        totalCreadits += ( (Double*) aGrade->credits->data[i] )->num;
    }

    return totalScores / totalCreadits;
}

// toString
void toStringStudent( Student* aStudent ) {
    printf("ID: %lu | Name: %s | Major: %s | className: %s | weightedGPA: %f\n",
           aStudent->ID, aStudent->name, aStudent->major, aStudent->className, aStudent->weightedGPA);
    printf("Courses: ");
    toStringGeneric( aStudent->myGrade.courses, toStringString );
    printf("Scores: ");
    toStringGeneric( aStudent->myGrade.scores, toStringDouble );
    printf("Credits: ");
    toStringGeneric( aStudent->myGrade.credits, toStringDouble );

}

// comparable
int compareToStudent(Student* aStudent1 , Student* aStudent2) {
    if (  fabs( aStudent1->weightedGPA - aStudent2->weightedGPA ) <= EPSILON ) // have some problem
        return 0;
    else if ( aStudent1->weightedGPA - aStudent2->weightedGPA < 0 )
        return -1;

    return 1;
}

// equals
int equalsStudent( Student* aStudent1, Student* aStudent2 ) {
    return aStudent1->ID == aStudent2->ID;
}
