#include <iostream>
#include "OperatorOverloadingTest.h"

using namespace std;

class MyInt {
private:
    int value = 0;
public:
    MyInt(int v = 0) {
        value = v;
    }
    // If we delete copy construct, assignment operator will not work
    //MyInt(const MyInt &tar) = delete;
    int getValue() {
        return value;
    }
    MyInt operator+(const MyInt &tar) {
        return MyInt(value + tar.value);
    }
    MyInt &operator=(const MyInt &tar) {
        if (this == &tar) {
            return *this;
        }
        value = tar.value;
        return *this;
    }
};

void OperatorOverloadingTest::start() {
    cout << ">>> OperatorOverloadingTest" << endl;

    MyInt a(5);
    MyInt b(7);
    MyInt c = a;

    cout << "a: " << a.getValue() << endl;
    cout << "b: " << b.getValue() << endl;
    cout << "c: " << c.getValue() << endl;
    cout << "a + b: " << (a + b).getValue() << endl;

    b = b + b;
    cout << "b = b + b: " << b.getValue() << endl;
}

void OperatorOverloadingTest::stop() {
    cout << "<<< OperatorOverloadingTest" << endl;
}