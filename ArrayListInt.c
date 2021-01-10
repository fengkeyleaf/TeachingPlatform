#include "ArrayListInt.h"

// constructor operations
ArrayListInt* createArrayListInt( const int* data, size_t len ) {
    ArrayListInt* aArrayListInt = (ArrayListInt*) malloc( sizeof(ArrayListInt) );
    aArrayListInt->capacity = len;
    aArrayListInt->index = len;
    extendArrayInt( aArrayListInt, data );
    return aArrayListInt;
}

ArrayListInt* createArrayListIntDefaultCapacity() {
    return createArrayListIntWithCapacity( 8 );
}

ArrayListInt* createArrayListIntWithCapacity( size_t capacity ) {
    ArrayListInt* aArrayListInt = (ArrayListInt*) malloc( sizeof(ArrayListInt) );
    aArrayListInt->capacity = capacity;
    aArrayListInt->index = 0;
    aArrayListInt->data = (int*) malloc( capacity * sizeof(int) );
    return aArrayListInt;
}

// add operations
void appendArrayListInt( ArrayListInt* aArrayListInt, int element ) {
    aArrayListInt->data[ aArrayListInt->index++ ] = element;

    if ( aArrayListInt->index >= aArrayListInt->capacity ) {
        int* oldArray = aArrayListInt->data;
        extendArrayInt( aArrayListInt, oldArray );
        free( oldArray );
    }
}

void insertArrayListInt( ArrayListInt* aArrayListInt, int index, int element) {
    if ( index < 0 || index > aArrayListInt->index ) {
        fprintf(stderr, "\nError: index is out of range!\n");
        exit(1);
    }
    else if ( index == aArrayListInt->index ) {
        appendArrayListInt(aArrayListInt, element);
        return;
    }

    aArrayListInt->index++;
    if ( aArrayListInt->index >= aArrayListInt->capacity ) {
        int* oldArray = aArrayListInt->data;
        extendArrayInt( aArrayListInt, oldArray );
        free( oldArray );
    }

//    printf("test\n");
    for (int i = aArrayListInt->index - 1; i > index; i--)
        aArrayListInt->data[i] = aArrayListInt->data[i - 1];
    aArrayListInt->data[index] = element;
}

void extendArrayInt( ArrayListInt* aArrayListInt, const int* data ) {
    aArrayListInt->data = (int*) malloc( aArrayListInt->capacity * 2 * sizeof(int) );
    copyIntArray( aArrayListInt->data, data, 0, aArrayListInt->capacity );
//    aArrayListInt->index = aArrayListInt->len;
    aArrayListInt->capacity = aArrayListInt->capacity * 2;
}

void copyIntArray( int* des, const int* src, size_t start, size_t ending ) {
    for (int i = start; i < ending; i++)
        des[i] = src[i];
}

// delete operations
int deleteLastArrayListInt( ArrayListInt* aArrayListInt ) {
    if ( isEmptyArrayListInt(aArrayListInt) ) {
        fprintf(stderr, "\nError: ArrayListInt is empty\n");
        exit(1);
    }
    int temp = aArrayListInt->data[ --aArrayListInt->index ];

    reorangeArrayListInt( aArrayListInt );
    return temp;
}

int deleteIndexArrayListInt( ArrayListInt* aArrayListInt, size_t index ) {
    if ( isEmptyArrayListInt(aArrayListInt) ) {
        fprintf(stderr, "\nError: ArrayListInt is empty\n");
        exit(1);
    }

    if ( checkIfIndexValid( aArrayListInt, index ) ) {
        fprintf(stderr, "\nError: index is out of range!\n");
        exit(1);
    }

    int temp = aArrayListInt->data[ index ];

    for ( int i = index + 1; i < aArrayListInt->index; i++ ) {
        aArrayListInt->data[i - 1] = aArrayListInt->data[i];
    }

    aArrayListInt->index--;
    reorangeArrayListInt( aArrayListInt );
    return temp;
}

void reorangeArrayListInt( ArrayListInt* aArrayListInt ) {
    if ( aArrayListInt->index < 5 ) return;

    if ( ( aArrayListInt->index - 1 ) * 2 <= aArrayListInt->capacity / 2 ) {
        int* oldArray = aArrayListInt->data;
        shrinkArrayInt( aArrayListInt, oldArray );
        free( oldArray );
    }
}

void shrinkArrayInt( ArrayListInt* aArrayListInt, const int* data ) {
    aArrayListInt->data = (int*) malloc( ( aArrayListInt->capacity / 2 ) * sizeof(int) );
    copyIntArray( aArrayListInt->data, data, 0, aArrayListInt->index );
    aArrayListInt->capacity = aArrayListInt->capacity / 2;
}

// obtain operations
int getArrayListInt( ArrayListInt* aArrayListInt, int index ) {
    if ( isEmptyArrayListInt(aArrayListInt) ) {
        fprintf(stderr, "\nError: ArrayListInt is empty\n");
        exit(1);
    }

    if ( checkIfIndexValid( aArrayListInt, index ) ) {
        fprintf(stderr, "\nError: index is out of range!\n");
        exit(1);
    }

    return aArrayListInt->data[index];
}

int checkIfIndexValid( ArrayListInt* aArrayListInt, int index ) {
    return index < 0 || index >= aArrayListInt->index;
}

int isEmptyArrayListInt( ArrayListInt* aArrayListInt ) {
    return aArrayListInt->index == 0;
}

// find operations
int linearSearchArrayListInt( ArrayListInt* aArrayListInt, int target ) {
    for ( int i = 0; i < aArrayListInt->index; i++ ) {
        if ( aArrayListInt->data[i] == target)
            return i;
    }

    return -1;
}

// sort operations
void selectionSortArrayListInt( ArrayListInt* aArrayListInt, int ascending ) {
    for ( int i = aArrayListInt->index - 1; i > 0; i--) {
        int maxNum = aArrayListInt->data[i];
        int indexMax = i;

        for (int j = i; j >= 0; j--) {
            if (aArrayListInt->data[j] > maxNum) {
                maxNum = aArrayListInt->data[j];
                indexMax = j;
            }
        }

        swapTwoInt(aArrayListInt, indexMax, i);
    }

    if ( ascending == FALSE ) reverseArrayListInt( aArrayListInt );
}

void reverseArrayListInt( ArrayListInt* aArrayListInt ) {
    int left = 0, right = aArrayListInt->index - 1;
    while ( left < right ) {
        swapTwoInt( aArrayListInt, left++, right-- );
    }
}

void swapTwoInt( ArrayListInt* aArrayListInt, int i, int j ) {
    int temp = aArrayListInt->data[i];
    aArrayListInt->data[i] = aArrayListInt->data[j];
    aArrayListInt->data[j] = temp;
}

void quickSortArrayListInt( ArrayListInt* aArrayListInt, int ascending ) {
    myQuickSortArrayListInt( aArrayListInt, 0, aArrayListInt->index - 1 );

    if ( ascending == FALSE ) reverseArrayListInt( aArrayListInt );
}

void myQuickSortArrayListInt( ArrayListInt* aArrayListInt, int start, int ending ) {
    if (ending <= start) return;

    int pivotIndex = partitionArrayListInt( aArrayListInt, start, ending );
    myQuickSortArrayListInt( aArrayListInt, start, pivotIndex - 1);
    myQuickSortArrayListInt( aArrayListInt, pivotIndex + 1, ending);
}

int partitionArrayListInt( ArrayListInt* aArrayListInt, int start, int ending ) {
    time_t t;
    srand( (unsigned) time( &t ) );
    int pivotIndex =  start + ( rand() % ( ending - start + 1 ) );
    int pivot = aArrayListInt->data[pivotIndex];
    swapTwoInt( aArrayListInt, start, pivotIndex);
//    int pivot = aArrayListInt->data[ start ];

    int i = start + 1;
    for (int j = start + 1; j <= ending; j++) {
        if ( pivot > aArrayListInt->data[j] ) {
            swapTwoInt(aArrayListInt, i++, j);
        }
    }

    swapTwoInt(aArrayListInt, start, i - 1);
    return i - 1;
}

// print
void printArrayListInt( ArrayListInt* aArrayListInt ) {
    printf("[ ");
    for (int i = 0; i < aArrayListInt->index; i++)
        printf("%d ", aArrayListInt->data[i] );
    printf("] | size: %d\n", aArrayListInt->index);
}

// test
void testArrayListInt() {
//    char* name = "himea";
//    char* name2 = "himeaa";
//    char* name3 = "himed";
//    char* name4[5];
//    strcpy(name4, name3);
//    printf("len: %d\n", strlen(name));
//    printf("%s\n", name4);
//
//    char name[6] = "himea";
//    char name2[7] = "himeaa";
//    char name3[6] = "himed";
//    strcpy(name, name3);
//    printf("len: %d\n", strlen(name));
//    printf("%s\n", name);

//    ArrayList * aArrayList = createArrayList( name, strlen( name ) );
//    printf("%s - %d", (char*) aArrayList->data, aArrayList->len);
//    free(aArrayList);
//    char* courses[] = { "math", "English", "Chinese" };
//    double scores[] = { 90.0, 95.1, 80 };
//    char** myCourses = courses;
//    size_t credits[] = {4, 6, 9 };
//    Grade aGrade;
//    aGrade.len = 3;
//    aGrade.courses = courses;
//    aGrade.credits = credits;
//    aGrade.scores = scores;
//    printGrade( &aGrade );

//    int* numMy = (int*) malloc( 8 * sizeof(int) );
//    memcpy(numMy, nums, 4);
//    copyIntArray(numMy, nums, 4);
//
//    for (int i = 0; i < 5; i++)
//        printf("%d ", numMy[i]);

    // test createArrayListInt() and appendArrayListInt
    int nums[] = { 1, 2, 3, 4 };
    ArrayListInt* aArrayListInt = createArrayListInt(nums, 4);
    printArrayListInt( aArrayListInt );

    appendArrayListInt(aArrayListInt, 5);
    printArrayListInt( aArrayListInt );

    appendArrayListInt(aArrayListInt, 6);
    appendArrayListInt(aArrayListInt, 7);
    appendArrayListInt(aArrayListInt, 8);
    printArrayListInt( aArrayListInt );

    // test appendArrayListInt()
    insertArrayListInt(aArrayListInt, 0, 0);
    printArrayListInt( aArrayListInt );
    insertArrayListInt(aArrayListInt, 1, 9);
    printArrayListInt( aArrayListInt );
    insertArrayListInt(aArrayListInt, 2, 10);
    printArrayListInt( aArrayListInt );
    insertArrayListInt(aArrayListInt, aArrayListInt->index - 1, 11);
    printArrayListInt( aArrayListInt );
    insertArrayListInt(aArrayListInt, aArrayListInt->index, 12);
    printArrayListInt( aArrayListInt );
//    insertArrayListInt(aArrayListInt, aArrayListInt->index + 1, 12); // invalid
//    insertArrayListInt(aArrayListInt, -1, 12); // invalid

    // test deleteLastArrayListInt()
    printf("\ntest deleteLastArrayListInt()----------->\n");
    printf("deleted: %d ->", deleteLastArrayListInt( aArrayListInt ) );
    printArrayListInt( aArrayListInt );
    printf("deleted: %d ->", deleteLastArrayListInt( aArrayListInt ) );
    printArrayListInt( aArrayListInt );
    printf("deleted: %d ->", deleteLastArrayListInt( aArrayListInt ) );
    printArrayListInt( aArrayListInt );
    printf("deleted: %d ->", deleteLastArrayListInt( aArrayListInt ) );
    printArrayListInt( aArrayListInt );

    // test deleteIndexArrayListInt()
    printf("\ntest deleteIndexArrayListInt()----------->\n");
    printf("deleted: %d ->", deleteIndexArrayListInt( aArrayListInt,  0) );
    printArrayListInt( aArrayListInt );
    printf("deleted: %d ->", deleteIndexArrayListInt( aArrayListInt,  1) );
    printArrayListInt( aArrayListInt );
    printf("deleted: %d ->", deleteIndexArrayListInt( aArrayListInt,  aArrayListInt->index - 1) );
    printArrayListInt( aArrayListInt );
    printf("deleted: %d ->", deleteIndexArrayListInt( aArrayListInt,  aArrayListInt->index - 1) );
    printArrayListInt( aArrayListInt );
    printf("deleted: %d ->", deleteIndexArrayListInt( aArrayListInt,  aArrayListInt->index - 1) );
    printArrayListInt( aArrayListInt );
    printf("deleted: %d ->", deleteIndexArrayListInt( aArrayListInt,  aArrayListInt->index - 1) );
    printArrayListInt( aArrayListInt );
    printf("deleted: %d ->", deleteIndexArrayListInt( aArrayListInt,  aArrayListInt->index - 1) );
    printArrayListInt( aArrayListInt );

    // test refresh
    printf("\n test refresh---------->\n");
    appendArrayListInt(aArrayListInt, 5);
    printArrayListInt( aArrayListInt );
    appendArrayListInt(aArrayListInt, 6);
    printArrayListInt( aArrayListInt );
    appendArrayListInt(aArrayListInt, -3);
    printArrayListInt( aArrayListInt );

    // test getArrayListInt()
    printf("\n test getArrayListInt---------->\n");
    printf("get at 0: %d ->\n", getArrayListInt( aArrayListInt,  0 ) );
    printf("get at 1: %d ->\n", getArrayListInt( aArrayListInt,  1 ) );
    printf("get at 2: %d ->\n", getArrayListInt( aArrayListInt,  2 ) );
    printf("get at 3: %d ->\n", getArrayListInt( aArrayListInt,  3 ) );
    printf("get at 4: %d ->\n", getArrayListInt( aArrayListInt,  4 ) );
    printArrayListInt( aArrayListInt );
//    printf("get at -1: %d ->\n", getArrayListInt( aArrayListInt,  -1 ) ); // invalid
//    printf("get at 5: %d ->\n", getArrayListInt( aArrayListInt,  5 ) ); // invalid

    // test linearSearchArrayListInt()
    printf("\n test linearSearchArrayListInt---------->\n");
    printf("find 9: %d ->\n", linearSearchArrayListInt( aArrayListInt,  9 ) );
    printf("find 1: %d ->\n", linearSearchArrayListInt( aArrayListInt,  1 ) );
    printf("find 6: %d ->\n", linearSearchArrayListInt( aArrayListInt,  6 ) );
    printf("find -3: %d ->\n", linearSearchArrayListInt( aArrayListInt,  -3 ) );
    printf("find -10: %d ->\n", linearSearchArrayListInt( aArrayListInt,  -10 ) );
    printf("find 100: %d ->\n", linearSearchArrayListInt( aArrayListInt,  100 ) );

    // test selectionSortArrayListInt()
    printf("\n test selectionSortArrayListInt---------->\n");
    selectionSortArrayListInt( aArrayListInt, TRUE );
    printArrayListInt( aArrayListInt );

    aArrayListInt->data[0] = 9;
    aArrayListInt->data[1] = 6;
    aArrayListInt->data[2] = 5;
    aArrayListInt->data[3] = 1;
    aArrayListInt->data[4] = -3;

    selectionSortArrayListInt( aArrayListInt, TRUE );
    printArrayListInt( aArrayListInt );

    deleteLastArrayListInt( aArrayListInt );
    deleteLastArrayListInt( aArrayListInt );
    deleteLastArrayListInt( aArrayListInt );
    reverseArrayListInt( aArrayListInt );
    printArrayListInt( aArrayListInt );
    selectionSortArrayListInt( aArrayListInt, TRUE );
    printArrayListInt( aArrayListInt );

    // test quickSort()
    printf("\n test quickSort---------->\n");
    appendArrayListInt( aArrayListInt, -4);
    appendArrayListInt( aArrayListInt, 9);
    appendArrayListInt( aArrayListInt, 5);
    printArrayListInt( aArrayListInt );
    quickSortArrayListInt( aArrayListInt, TRUE );
    printArrayListInt( aArrayListInt );
    free( aArrayListInt->data );
    free( aArrayListInt );

    // test constructors
    printf("\n test constructors---------->\n");
    aArrayListInt = createArrayListIntDefaultCapacity();
    printArrayListInt( aArrayListInt );
    appendArrayListInt( aArrayListInt, 1 );
    insertArrayListInt( aArrayListInt, 0, 2);
    printArrayListInt( aArrayListInt );
    deleteLastArrayListInt( aArrayListInt );
    printArrayListInt( aArrayListInt );
    // test random
//    time_t t;
//    srand( (unsigned) time( &t ) );
//    int start = 2, ending = 5;
//    printf("%d", start + ( rand() % ( ending - start + 1 ) ));
}

