#include <iostream>
#include "TemplateTest.h"

using namespace std;

template<class T>
class TempSort {
public:
    static bool insertionSort(T array[], int length) {
        if (length <= 0) {
            return false;
        }

        for (int i = 1; i < length; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (array[j] > array[j + 1]) {
                    T tmp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = tmp;
                } else {
                    break;
                }
            }
        }

        return true;
    }

    static void printArray(T array[], int length) {
        cout << "[";
        for (int i = 0; i < length; i++) {
            if (i > 0) {
                cout << ", " << array[i];
            } else {
                cout << array[i];
            }
        }
        cout << "]" << endl;
    }
};

void TemplateTest::start() {
    cout << ">>> TemplateTest" << endl;

    int intArray[10] = { 5, 3, 8, 2, 6, 9, 7, 4, 1, 0 };
    cout << "Int array BEFORE sort:" << endl;
    TempSort<int>::printArray(intArray, 10);
    TempSort<int>::insertionSort(intArray, 10);
    cout << "Int array AFTER sort:" << endl;
    TempSort<int>::printArray(intArray, 10);

    cout << "****************************" << endl;

    float floatArray[10] = { 5.5, 3.3, 8.8, 2.2, 6.6, 9.9, 7.7, 4.4, 1.1, 0.0 };
    cout << "Float array BEFORE sort:" << endl;
    TempSort<float>::printArray(floatArray, 10);
    TempSort<float>::insertionSort(floatArray, 10);
    cout << "Float array AFTER sort:" << endl;
    TempSort<float>::printArray(floatArray, 10);

    double array2d[3][5] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.0, 7.0, 8.0, 9.0, 10.0},
        {11.0, 12.0, 13.0, 14.0, 15.0}
    };
    print2dArray(array2d);
}

void TemplateTest::stop() {
    cout << "<<< TemplateTest" << endl;
}