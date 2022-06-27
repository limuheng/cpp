#ifndef _TEMPLATE_TEST_
#define _TEMPLATE_TEST_

#include "ITest.h"
#include <iomanip>

using namespace std;

class TemplateTest : public ITest {
private:
    template <typename T, size_t rows, size_t cols>
    void print2dArray(T (&array)[rows][cols]) {
        cout << "2D Array: " << endl;
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols - 1; j++) {
                cout << setw(4) << setfill(' ') << array[i][j] << ", ";
            }
            cout << setw(4) << setfill(' ') << array[i][cols - 1] << endl;
        }
    }
public:
    void start() override;
    void stop() override;
};

#endif