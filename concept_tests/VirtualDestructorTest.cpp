#include <iostream>
#include "VirtualDestructorTest.h"

using namespace std;

class A {
public:
    A() {
        cout << "A(" << this << ")" << endl;
    }
    // If parent class destructor is not declared as virtual,
    // then only parent's destructor be invoked when deleting a parent class pointer.
    ~A() {
        cout << "~A(" << this << ")" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "B(" << this << ")" << endl;
    }
    ~B() {
        cout << "~B(" << this << ")" << endl;
    }
};

class C {
public:
    C() {
        cout << "C(" << this << ")" << endl;
    }
    virtual ~C() {
        cout << "~C(" << this << ")" << endl;
    }
};

class D : public C {
public:
    D() {
        cout << "D(" << this << ")" << endl;
    }
    ~D() {
        cout << "~D(" << this << ")" << endl;
    }
};

void VirtualDestructorTest::start() {
    cout << ">>> VirtualDestructorTest" << endl;

    A *a = new B();
    C *c = new D();

    // Since ~A() is not virtual, so when we delete a,
    // only ~A() is invoked.
    delete a;
    // Since ~C() is virtual, so when we delete c,
    // ~D() & ~C() are invoked in sequence.
    delete c;
}

void VirtualDestructorTest::stop() {
    cout << "<<< VirtualDestructorTest" << endl;
}