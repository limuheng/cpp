#ifndef _MEMORY_TEST_
#define _MEMORY_TEST_

#include "ITest.h"
#include <iomanip>

using namespace std;

class DynamicArrayTest : public ITest {
private:
    template<typename T>
    void print(T array[], size_t length);
    void print2dArray(int **array, size_t rows, size_t cols);
public:
    void start() override;
    void stop() override;
};

template<typename T>
void DynamicArrayTest::print(T array[], size_t length) {
    cout << "Array: ";
    for (size_t i = 0; i < length - 1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[length - 1] << endl;
};


#endif