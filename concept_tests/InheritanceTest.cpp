#include <iostream>
#include "InheritanceTest.h"

using namespace std;

class A {
public:
    A() {
        cout << "A(" << this << ")" << endl;
    }
    virtual ~A() {
        cout << "~A(" << this << ")" << endl;
    }
    int getX() {
        return x;
    };
    void function1() {
        cout << "A::function1(101)" << endl;
        x = 101;
    };
    virtual void function2() {
        cout << "A::function2(102)" << endl;
        x = 102;
    };
protected:
    int x = 0;
};

class B : public A {
public:
    B() {
        cout << "B(" << this << ")" << endl;
    }
    ~B() {
        cout << "~B(" << this << ")" << endl;
    }
    // Normal Override
    void function1() {
        cout << "B::function1(201)" << endl;
        x = 201;
    };
    // Virtual Override
    void function2() override {
        cout << "B::function2(202)" << endl;
        x = 202;
    };
};

void InheritanceTest::start() {
    cout << ">>> InheritanceTest" << endl;

    B b;
    // Pointer Test
    A *a;
    // Copy Test
    A a1;

    a = &b;
    a1 = b;

    // Calls B's function1
    b.function1();
    // Calls B's function2
    b.function2();

    // function2 is virtual, so this calls B's function2
    a->function2();
    // function1 is not virtual, so this calls A's function1
    a->function1();

    // a1 is an instance of class A
    // Calls A's function1
    a1.function1();
    // Calls A's function2
    a1.function2();

    cout << "b.getX(): " << b.getX() << endl;
    cout << "a->getX(): " << a->getX() << endl;
    cout << "a1.getX(): " << a1.getX() << endl;
}

void InheritanceTest::stop() {
    cout << "<<< InheritanceTest" << endl;
}
