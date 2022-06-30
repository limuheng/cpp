#ifndef _UTILS_
#define _UTILS_

#include <iostream>
#include <cstddef>

using namespace std;

template<typename T>
void print(string text, T array[], size_t length) {
    cout << text << ": ";
    for (size_t i = 0; i < length - 1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[length - 1] << endl;
};


#endif