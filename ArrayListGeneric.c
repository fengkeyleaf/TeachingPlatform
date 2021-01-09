#include "ArrayListGeneric.h"

// constructor operations
ArrayListGeneric* createArrayListGeneric( void* const * data, size_t len ) {
    ArrayListGeneric* aArrayListGeneric = (ArrayListGeneric*) malloc( sizeof(ArrayListGeneric) );
    aArrayListGeneric->capacity = len;
    aArrayListGeneric->index = len;
    extendArrayListGeneric( aArrayListGeneric, data );
    return aArrayListGeneric;
}

ArrayListGeneric* createArrayListGenericDefaultCapacity() {
    return createArrayListGenericWithCapacity( 8 );
}

ArrayListGeneric* createArrayListGenericWithCapacity( size_t capacity ) {
    ArrayListGeneric* aArrayListGeneric = (ArrayListGeneric*) malloc( sizeof(ArrayListGeneric) );
    aArrayListGeneric->capacity = capacity;
    aArrayListGeneric->index = 0;
    aArrayListGeneric->data = (void**) malloc( capacity * sizeof(void*) );
    return aArrayListGeneric;
}

// add operations
void appendArrayListGeneric ( ArrayListGeneric* aArrayListGeneric, void* element ) {
    aArrayListGeneric->data[ aArrayListGeneric->index++ ] = element;

    if ( aArrayListGeneric->index >= aArrayListGeneric->capacity ) {
        void** oldArray = aArrayListGeneric->data;
        extendArrayListGeneric( aArrayListGeneric, (void* const *) oldArray );
        free( oldArray );
    }
}

void insertArrayListGeneric( ArrayListGeneric* aArrayListGeneric, void* element , int index ) {
    if ( index < 0 || index > aArrayListGeneric->index ) {
        fprintf(stderr, "\nError: index is out of range!\n");
        exit(1);
    }
    else if ( index == aArrayListGeneric->index ) {
        appendArrayListGeneric(aArrayListGeneric, element);
        return;
    }

    aArrayListGeneric->index++;
    if ( aArrayListGeneric->index >= aArrayListGeneric->capacity ) {
        void** oldArray = aArrayListGeneric->data;
        extendArrayListGeneric( aArrayListGeneric, (void* const *) oldArray );
        free( oldArray );
    }

//    printf("test\n");
    for (int i = aArrayListGeneric->index - 1; i > index; i--)
        aArrayListGeneric->data[i] = aArrayListGeneric->data[i - 1];
    aArrayListGeneric->data[index] = element;
}


void extendArrayListGeneric( ArrayListGeneric* aArrayListGeneric, void* const * data ) {
    aArrayListGeneric->data = (void**) malloc( aArrayListGeneric->capacity * 2 * sizeof(void*) );
    copyArrayListGeneric( aArrayListGeneric->data, data, 0, aArrayListGeneric->capacity );
//    aArrayListInt->index = aArrayListInt->len;
    aArrayListGeneric->capacity = aArrayListGeneric->capacity * 2;
}

void copyArrayListGeneric( void** des, void* const * src, size_t start, size_t ending ) {
    for (int i = start; i < ending; i++)
        des[i] = src[i];
}

// delete operations
void* deleteLastArrayListGeneric( ArrayListGeneric* aArrayListGeneric ) {
    if ( isEmptyArrayListGeneric( aArrayListGeneric ) ) {
        fprintf(stderr, "\nError: ArrayListInt is empty\n");
        exit(1);
    }
    void* temp = aArrayListGeneric->data[ --aArrayListGeneric->index ];

    reorangeArrayListGeneric( aArrayListGeneric );
    return temp;
}

void* deleteIndexArrayListGeneric( ArrayListGeneric* aArrayListGeneric, int index ) {
    if ( isEmptyArrayListGeneric(aArrayListGeneric) ) {
        fprintf(stderr, "\nError: ArrayListInt is empty\n");
        exit(1);
    }

    if ( checkIfIndexValidGeneric( aArrayListGeneric, index ) ) {
        fprintf(stderr, "\nError: index is out of range!\n");
        exit(1);
    }

    void* temp = aArrayListGeneric->data[ index ];

    for ( int i = index + 1; i < aArrayListGeneric->index; i++ ) {
        aArrayListGeneric->data[i - 1] = aArrayListGeneric->data[i];
    }

    aArrayListGeneric->index--;
    reorangeArrayListGeneric( aArrayListGeneric );
    return temp;
}

// obtain operations
void* getArrayListGeneric ( ArrayListGeneric* aArrayListGeneric, int index ) {
    if ( isEmptyArrayListGeneric(aArrayListGeneric) ) {
        fprintf(stderr, "\nError: ArrayListInt is empty\n");
        exit(1);
    }

    if ( checkIfIndexValidGeneric( aArrayListGeneric, index ) ) {
        fprintf(stderr, "\nError: index is out of range!\n");
        exit(1);
    }

    return aArrayListGeneric->data[index];
}

int isEmptyArrayListGeneric( ArrayListGeneric* aArrayListGeneric ) {
    return aArrayListGeneric->index == 0;
}

int checkIfIndexValidGeneric( ArrayListGeneric* aArrayListGeneric, int index ) {
    return index < 0 || index >= aArrayListGeneric->index;
}

void reorangeArrayListGeneric( ArrayListGeneric* aArrayListGeneric ) {
    if ( aArrayListGeneric->index < 5 ) return;

    if ( ( aArrayListGeneric->index - 1 ) * 2 <= aArrayListGeneric->capacity / 2 ) {
        void** oldArray = aArrayListGeneric->data;
        shrinkArrayListGeneric( aArrayListGeneric, (void* const *) oldArray );
        free( oldArray );
    }
}

void shrinkArrayListGeneric( ArrayListGeneric* aArrayListGeneric, void* const * data ) {
    aArrayListGeneric->data = (void**) malloc( ( aArrayListGeneric->capacity / 2 ) * sizeof(void*) );
    copyArrayListGeneric( aArrayListGeneric->data, data, 0, aArrayListGeneric->index );
    aArrayListGeneric->capacity = aArrayListGeneric->capacity / 2;
}

// find operations
int linearSearchGeneric( ArrayListGeneric* aArrayListGeneric, void* target, int (*equalsGeneric)(void*, void*) ) {
    for ( int i = 0; i < aArrayListGeneric->index; i++ ) {
//        if ( ( (Integer*) aArrayListGeneric->data[i] )->num == target->num )
    printf("test");
        if ( equalsGeneric( aArrayListGeneric->data[i], target ) )
            return i;
    }

    return -1;
}

// sort operations
// selection sort
void selectionSortGeneric( ArrayListGeneric* aArrayListGeneric, int ascending, int (*compareToGeneric)(void*, void*) ) {
    for ( int i = aArrayListGeneric->index - 1; i > 0; i--) {
        void* maxNum = aArrayListGeneric->data[i];
        int indexMax = i;

        for (int j = i; j >= 0; j--) {
//            if ( compareToInteger( (Integer*) aArrayListGeneric->data[j], maxNum ) > 0 ) {
            if ( compareToGeneric( aArrayListGeneric->data[j], maxNum ) > 0 ) {
                maxNum = aArrayListGeneric->data[j];
                indexMax = j;
            }
        }

        swapTwoGerneric( aArrayListGeneric, indexMax, i );
    }

    if ( ascending == FALSE ) reverseGerneric( aArrayListGeneric );
}

void swapTwoGerneric( ArrayListGeneric* aArrayListGeneric, int i, int j ) {
    void* temp = aArrayListGeneric->data[i];
    aArrayListGeneric->data[i] = aArrayListGeneric->data[j];
    aArrayListGeneric->data[j] = temp;
}

void reverseGerneric( ArrayListGeneric* aArrayListGeneric ) {
    int left = 0, right = aArrayListGeneric->index - 1;
    while ( left < right ) {
        swapTwoGerneric( aArrayListGeneric, left++, right-- );
    }
}

// quickSort
void quickSortGeneric( ArrayListGeneric* aArrayListGeneric, int ascending, int (*compareToGeneric)(void*, void*) ) {
    myQuickSortGeneric( aArrayListGeneric, 0, aArrayListGeneric->index - 1, compareToGeneric );

    if ( ascending == FALSE ) reverseGerneric( aArrayListGeneric );
}

void myQuickSortGeneric(  ArrayListGeneric* aArrayListGeneric, int start, int ending, int (*compareToGeneric)(void*, void*) ) {
    if ( ending <= start ) return;

    int pivotIndex = partitionGeneric( aArrayListGeneric, start, ending, compareToGeneric );
    myQuickSortGeneric( aArrayListGeneric, start, pivotIndex - 1, compareToGeneric );
    myQuickSortGeneric( aArrayListGeneric, pivotIndex + 1, ending, compareToGeneric );
}

int partitionGeneric( ArrayListGeneric* aArrayListGeneric, int start, int ending, int (*compareToGeneric)(void*, void*) ) {
    time_t t;
    srand( (unsigned) time( &t ) );
    int pivotIndex = start + ( rand() % ( ending - start + 1 ) );
    void* pivot = aArrayListGeneric->data[ pivotIndex ];
    swapTwoGerneric( aArrayListGeneric, start, pivotIndex );
//     Integer* pivot = (Integer*) aArrayListGeneric->data[ start ];
//    Integer* pivot = (Integer*) aArrayListGeneric->data[ ending ];
//    swapTwoGerneric( aArrayListGeneric, start, ending );

    int i = start + 1;
    for (int j = start + 1; j <= ending; j++) {
        // function pointer
        // https://www.runoob.com/cprogramming/c-fun-pointer-callback.html
        if ( compareToGeneric( pivot, aArrayListGeneric->data[j] ) > 0 ) {
            swapTwoGerneric(aArrayListGeneric, i++, j);
        }
    }

    swapTwoGerneric(aArrayListGeneric, start, i - 1);
    return i - 1;
}

// toString
void toStringGeneric( ArrayListGeneric* aArrayListGeneric, void (*toStringInstance)(void*) ) {
    printf("[ ");
    for ( int i = 0; i < aArrayListGeneric->index; i++ )
        toStringInstance( aArrayListGeneric->data[i] );
    printf("] | size: %d\n", aArrayListGeneric->index );
}

// test
void testArrayGenericWithInteger() {
    // test createArrayListGeneric() and appendArrayListGeneric
    printf("\n test createArrayListGeneric() and appendArrayListGeneric()---------->\n");
    Integer* nums[3];
    Integer num1;
    num1.num = 1;
    Integer num2;
    num2.num = 2;
    Integer num3;
    num3.num = 3;
    nums[0] = &num1;
    nums[1] = &num2;
    nums[2] = &num3;

    ArrayListGeneric* aArrayListGeneric = createArrayListGeneric( (void**) nums, 3);
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
    Integer num4;
    num4.num = 4;
    Integer num5;
    num5.num = 5;
    Integer num6;
    num6.num = 6;
//    insertArrayListGeneric(aArrayListGeneric, &num4, 0);
    appendArrayListGeneric( aArrayListGeneric, &num4 );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
//    appendArrayListGeneric( aArrayListGeneric, &num5 );
//    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
//    appendArrayListGeneric( aArrayListGeneric, &num6 );
//    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);

    // test insertArrayListGeneric()
    printf("\n test insertArrayListGeneric()---------->\n");
    insertArrayListGeneric(aArrayListGeneric, &num5, 0);
    insertArrayListGeneric(aArrayListGeneric, &num6, aArrayListGeneric->index);
//    printf("%d\n", aArrayListGeneric->index);
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);

    // test deleteLastArrayListGeneric()
    printf("\n test delete()---------->\n");
    printf("deleted: %d ->", ( (Integer*) deleteLastArrayListGeneric( aArrayListGeneric ) )->num );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
    printf("deleted: %d ->", ( (Integer*) deleteIndexArrayListGeneric( aArrayListGeneric, 0 ) )->num );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
    printf("deleted: %d ->", ( (Integer*) deleteIndexArrayListGeneric( aArrayListGeneric, aArrayListGeneric->index - 1 ) )->num );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
//    printf("deleted: %d ->", ( (Integer*) deleteIndexArrayListGeneric( aArrayListGeneric, aArrayListGeneric->index ) )->num ); invalid

    // test get()
    printf("\n test get---------->\n");
    printf("get at 0: %d ->\n", ( (Integer*) getArrayListGeneric( aArrayListGeneric,  0 ) )->num );
    printf("get at 1: %d ->\n", ( (Integer*) getArrayListGeneric( aArrayListGeneric,  1 ) )->num );
    printf("get at 2: %d ->\n", ( (Integer*) getArrayListGeneric( aArrayListGeneric,  2 ) )->num );
//    printf("get at 3: %d ->\n", ( (Integer*) getArrayListGeneric( aArrayListGeneric,  3 ) )->num );
//    printf("get at 4: %d ->\n", ( (Integer*) getArrayListGeneric( aArrayListGeneric,  4 ) )->num ); // invalid

    // test find()
    printf("\n test linearSearchArrayListInt---------->\n");
    printf("find num1: %d ->\n", linearSearchGeneric( aArrayListGeneric,  &num1, compareToInteger ) );
    printf("find num3: %d ->\n", linearSearchGeneric( aArrayListGeneric,  &num3, compareToInteger ) );
    printf("find num2: %d ->\n", linearSearchGeneric( aArrayListGeneric,  &num2, compareToInteger ) );
    printf("find num4: %d ->\n", linearSearchGeneric( aArrayListGeneric,  &num4, compareToInteger ) );
    printf("find num5: %d ->\n", linearSearchGeneric( aArrayListGeneric,  &num5, compareToInteger ) );

    // test selectionSort
    printf("\n test selectionSort---------->\n");
    reverseGerneric( aArrayListGeneric );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
    selectionSortGeneric( aArrayListGeneric, TRUE, compareToInteger );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
    selectionSortGeneric( aArrayListGeneric, FALSE, compareToInteger );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);

    // test quick sort
    printf("\n test quicksort---------->\n");
//    reverseGerneric( aArrayListGeneric );
//    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
    quickSortGeneric( aArrayListGeneric, TRUE, compareToInteger );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
    free( aArrayListGeneric->data );
    free( aArrayListGeneric );
    aArrayListGeneric = NULL;

    // test constructors
    printf("\n test constructors---------->\n");
    aArrayListGeneric = createArrayListGenericDefaultCapacity();
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
    appendArrayListGeneric( aArrayListGeneric, &num1 );
    insertArrayListGeneric( aArrayListGeneric, &num5, 0 );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
    deleteLastArrayListGeneric( aArrayListGeneric );
    printInteger( (Integer**)aArrayListGeneric->data, aArrayListGeneric->index);
}
