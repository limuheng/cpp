#include <iostream>
#include <string>
#include <string.h>

#include "CMemFuncTest.h"
#include "Utils.h"

using namespace std;

#define BUFFER_LENGTH 128

void CMemFuncTest::start() {
    cout << ">>> CMemFuncTest" << endl;

    size_t buffer_size = BUFFER_LENGTH * sizeof(int);
    int *buffer = (int *) malloc(buffer_size);
    memset(buffer, 0, buffer_size);

    const int array_length = 10;
    int *array = new int[array_length];
    for (int i = 0; i < array_length; i++) {
        array[i] = i + 1;
    }
    print("Array", array, array_length);

    size_t array_size = sizeof(int) * array_length;
    memcpy(buffer, array, array_size);
    cout << "Use memcpy to copy array:" << endl;
    print("Buffer", buffer, array_length);

    cout << "Is buffer equals to array: " <<
        ((memcmp(buffer, array, array_size) == 0) ? "Yes" : "No") << endl;

    int *p = (int *)memchr(buffer, 5, array_size);
    cout << "Use memchr to find next of 5: " << *(p + 1) << endl;

    cout << "Use memmove to override buffer:" << endl;
    cout << "Before move: " << endl;
    print("Buffer", buffer, array_length);                       // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    cout << "After move (move 5 elements from index 3 to start of buffer): " << endl;
    memmove(buffer, buffer + 3, sizeof(int) * 5);      // 4, 5, 6, 7, 8, 6, 7, 8, 9, 10 
    //memcpy(buffer, buffer + 3, sizeof(int) * 5);     // 4, 5, 6, 7, 8, 6, 7, 8, 9, 10
    //memmove(buffer + 3, buffer, sizeof(int) * 5);    // 1, 2, 3, 1, 2, 3, 4, 5, 9, 10
    //memcpy(buffer + 3, buffer, sizeof(int) * 5);     // 1, 2, 3, 1, 2, 3, 4, 5, 9, 10
    print("Buffer", buffer, array_length);

    cout << "Is buffer equals to array: " <<
        ((memcmp(buffer, array, array_size) == 0) ? "Yes" : "No") << endl;

    free(array);
    free(buffer);
}

void CMemFuncTest::stop() {
    cout << "<<< CMemFuncTest" << endl;
}
