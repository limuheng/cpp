#include <iostream>
#include "DynamicArrayTest.h"

using namespace std;

#define TEST_SIZE 10

#define CREATE_2D_ARRAY(rows,cols,TYPE) (TYPE**)create2dArray(rows, cols, sizeof(TYPE))

// Ref. https://smalldd.pixnet.net/blog/post/10953132
void *create2dArray(size_t rows, size_t cols, size_t element_size) {
    cout << "[create2dArray] rows: " << rows << ", cols: " << cols << ", size: " << element_size << endl;
    void **p;
    /**
     * space of pointers: rows*sizeof(void *)
     * space of data: size*rows*cols
     */
    p = (void **) new char[(rows*sizeof(void *)) + (element_size*rows*cols)];
    for (int i = 0; i < rows; i++) {
        p[i] = (char *)(p + rows + (i * cols * element_size));
    }
    return p;
}

void DynamicArrayTest::print2dArray(int **array, size_t rows, size_t cols) {
    if (!array) {
        return ;
    }
    cout << "2D Array: " << endl;
    for (size_t i = 0; i < rows; i++) {
        if (array[i]) {
            for (size_t j = 0; j < cols - 1; j++) {
                cout << setw(3) << setfill(' ') << array[i][j] << ", ";
            }
            cout << setw(3) << setfill(' ') << array[i][cols - 1] << endl;
        }
    }
}

void DynamicArrayTest::start() {
    cout << ">>> DynamicArrayTest" << endl;
    
    cout << "=== new test ===" << endl;

    cout << "1D array Test: " << endl;
    int *array = new int[TEST_SIZE];
    for (int i = 0; i < TEST_SIZE; i++) {
        array[i] = i + 1;
    }
    print(array, TEST_SIZE);

    delete [] array;

    /* ---------------- */

    cout << "2D array Test (created by iteration): " << endl;
    int **array2 = new int*[TEST_SIZE];
    for (int i = 0; i < TEST_SIZE; i++) {
        array2[i] = new int[TEST_SIZE];
        for (int j = 0; j < TEST_SIZE; j++) {
            array2[i][j] = i * j;
        }
    }
    cout << "Print array2: " << endl;
    print2dArray(array2, TEST_SIZE, TEST_SIZE);

    for (int i = 0; i < TEST_SIZE; i++) {
        delete [] array2[i];
    }
    delete [] array2;

    /* ---------------- */

    cout << "2D array Test (created by single block): " << endl;
    int *arrayblock = new int[TEST_SIZE * TEST_SIZE];
    int **array3 = new int*[TEST_SIZE];
    for (int i = 0; i < TEST_SIZE; i++) {
        array3[i] = &arrayblock[i * TEST_SIZE];
        for (int j = 0; j < TEST_SIZE; j++) {
            array3[i][j] = i * TEST_SIZE + j;
        }
    }
    cout << "Print array3: " << endl;
    print2dArray(array3, TEST_SIZE, TEST_SIZE);

    delete [] arrayblock;
    delete [] array3;

    /* ---------------- */

    cout << "2D array Test (created by single block 2): " << endl;
    int **array4 = CREATE_2D_ARRAY(TEST_SIZE, TEST_SIZE, int);
    for (int i = 0; i < TEST_SIZE; i++) {
        for (int j = 0; j < TEST_SIZE; j++) {
            array4[i][j] = (i * TEST_SIZE + j) * 2;
        }
    }
    cout << "Print array4: " << endl;
    print2dArray(array4, TEST_SIZE, TEST_SIZE);
    delete [] array4;

};

void DynamicArrayTest::stop() {
    cout << "<<< DynamicArrayTest" << endl;
};

