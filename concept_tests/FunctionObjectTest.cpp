#include <algorithm>
#include <iostream>
#include <vector>
#include "FunctionObjectTest.h"

using namespace std;

template<class T>
class Square {
public:
    T operator()(T num) {
        T result = num * num;
        cout << result << " ";
        return result;
    }
};

void FunctionObjectTest::start() {
    cout << ">>> FunctionObjectTest" << endl;

    cout << "Square of int list" << endl;
    vector<int> list = { 3, 7, 2, 5, 12 };
    for_each(list.begin(), list.end(), Square<int>());

    cout << endl << "Square of double list" << endl;
    vector<double> list2 = { 6.3, 2.7, 5.2, 80.5, 7.1 };
    for_each(list2.begin(), list2.end(), Square<double>());

    cout << endl;
}

void FunctionObjectTest::stop() {
    cout << "<<< FunctionObjectTest" << endl;
}
