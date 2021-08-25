#include <iostream>
#include "SizeOfTest.h"

using namespace std;


class EmptyClass {

};

class EmptyVirtualClass {
public:
    virtual void func() {}
};

void SizeOfTest::start() {
    cout << ">>> SizeOfTest" << endl;

    cout << "Size of EmptyClass is: " << sizeof(EmptyClass) << endl; // size: 1

    EmptyClass e;
    cout << "Size of EmptyClass instance is: " << sizeof(e) << endl; // size: 1

    cout << "Size of EmptyVirtualClass is: " << sizeof(EmptyVirtualClass) << endl; // size: 8

    EmptyVirtualClass ev;
    cout << "Size of EmptyVirtualClass instance is: " << sizeof(ev) << endl; // size: 8

    int a[] = { 0, 1, 2, 3, 4 };
    cout << "Size of a[] is: " << sizeof(a) << endl; // size: 20

    int *b = new int[10];
    cout << "Size of b is: " << sizeof(b) << endl; // size: 8

    cout << "length of a: " << sizeof(a) / sizeof(a[0]) << endl; // length = 5
    cout << "length of b: " << sizeof(b) / sizeof(b[0]) << endl; // Incorrect, can not calculate array length by a pointer
}

void SizeOfTest::stop() {
    cout << "<<< SizeOfTest" << endl;
}