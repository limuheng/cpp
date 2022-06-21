#include <iostream>
#include "SizeOfTest.h"

using namespace std;

class EmptyClass {

};

class EmptyVirtualClass {
public:
    virtual void func() {}
};

class SimpleClass {
private:
    int value;            // size: 4
    double value2;        // size: 8
    SimpleClass *next;    // size: 8
public:
    SimpleClass(int v, double d) : value(v), value2(d) { }
    void set(int v) {
        value = v;
    }
    int get() {
        return value;
    }
    SimpleClass *getNext() {
        return next;
    }
    /*
     * With virtual functions in class, the size of class will increase 8 bytes
     * which is the size of pointer to virtual function table.
     */
    virtual void set2(double v) {
        value2 = v;
    }
    virtual double get2() {
        return value2;
    }
} __attribute__((packed));

// __attribute__((packed)): tells compiler do not make alignment

struct TestStruct {
    int a;
    double b;
    TestStruct *p;
} /* __attribute__((packed)) */;

typedef struct TestStruct mystruct;

struct EmptyStruct {
} /* __attribute__((packed)) */;

void SizeOfTest::start() {
    cout << ">>> SizeOfTest" << endl;

    cout << "=== About class ===" << endl;
    cout << "Size of EmptyClass is: " << sizeof(EmptyClass) << endl;                // size: 1

    EmptyClass e;
    cout << "Size of EmptyClass instance is: " << sizeof(e) << endl;                // size: 1

    cout << "Size of EmptyVirtualClass is: " << sizeof(EmptyVirtualClass) << endl;  // size: 8

    EmptyVirtualClass ev;
    cout << "Size of EmptyVirtualClass instance is: " << sizeof(ev) << endl;        // size: 8

    SimpleClass s(10, 12.0);
    cout << "Size of SimpleClass instance is: " << sizeof(s) << endl;               // size: 32 (with alignment), 28 (w/o alignment)

    cout << "=== About array ===" << endl;
    int a[] = { 0, 1, 2, 3, 4 };
    cout << "Size of a[] is: " << sizeof(a) << endl;                   // size: 20, int size: 4 bytes

    int *b = new int[10];
    cout << "Size of b is: " << sizeof(b) << endl;                     // size: 8, pointer size on 64bit OS

    cout << "length of a: " << sizeof(a) / sizeof(a[0]) << " (O) " << endl; // length = 5
    cout << "length of b: " << sizeof(b) / sizeof(b[0]) << " (X) " << endl; // Incorrect, can not calculate array length by a pointer

    cout << "=== About primitive type ===" << endl;
    cout << "Size of int is: " << sizeof(int) << endl;                 // size: 4
    cout << "Size of double is: " << sizeof(double) << endl;           // size: 8
    cout << "Size of a pointer is: " << sizeof(EmptyClass *) << endl;  // size: 8

    cout << "=== About struct ===" << endl;
    cout << "Size of TestStruct is: " << sizeof(mystruct) << endl;     // size: 24 (with alignment), 20 (w/o alignment)

    cout << "Size of EmptyStruct is: " << sizeof(EmptyStruct) << endl; // size: 1

    mystruct t = {2, 2.2, nullptr};
    mystruct t2 = {3, 3.3, nullptr};
    mystruct array[2] = {
        {0, 0.0, &t}, {1, 1.1, &t2}
    };

    cout << "Size of array[0]: " << sizeof(array[0]) << endl;          // size: 24 (with alignment), 20 (w/o alignment)
    cout << "Size of array[1]: " << sizeof(array[1]) << endl;          // size: 24 (with alignment), 20 (w/o alignment)
    cout << "Size of mystruct array is: " << sizeof(array) << endl;    // size: 48 (with alignment), 40 (w/o alignment)

    cout << "Address of array[0]: " << &array[0] << endl;
    cout << "Address of array[1]: " << &array[1] << endl;

    uintptr_t addr1 = reinterpret_cast<uintptr_t>(&array[0]);  // reinterpret pointer to unsigned long int
    uintptr_t addr2 = reinterpret_cast<uintptr_t>(&array[1]);  // so we can calculate size by subtraction

    cout << "Reinterpret address of array[0]: " << addr1 << endl;
    cout << "Reinterpret address of array[1]: " << addr2 << endl;
    cout << "Size of mystruct is: " << addr2 - addr1 << endl;


}

void SizeOfTest::stop() {
    cout << "<<< SizeOfTest" << endl;
}