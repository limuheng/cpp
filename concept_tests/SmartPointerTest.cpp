#include <iostream>
#include <memory>
#include "SmartPointerTest.h"

using namespace std;

class TestObj {
public:
    TestObj(string v = "") : value(v) {
        cout << "Create TestObj(" << value << ")" << endl;
    };
    ~TestObj() {
        cout << "TestObj(" << value << ") was destroyed" << endl;
    };
    string getValue() {
        return value;
    };
    void clear() {
        value = "";
    };
    TestObj operator+(const TestObj &testObj) {
        return TestObj(value + " " + testObj.value);
    }
    TestObj &operator=(const TestObj &testObj) {
        value = testObj.value;
        return *this;
    }
private:
    string value;
};

bool increase(shared_ptr<int> p) {
    if (p) {
        cout << "use count of p: " << p.use_count() << endl;
        (*p)++;
    }
    return false;
}

void SmartPointerTest::start() {
    cout << ">>> SmartPointerTest" << endl;

    shared_ptr<int> p1 = make_shared<int>(100);
    // Different initialization
    //shared_ptr<int> p1 = make_shared<int>(new int(100));
    //shared_ptr<int> p1(new int(100));

    increase(p1);
    cout << "p1: " << *p1 << ", use count(p1): " << p1.use_count() << endl;

    shared_ptr<int> p2(p1);
    cout << "p2: " << *p2 << ", use count(p2): " << p2.use_count() << endl;

    p2.reset();
    cout << "p1: " << *p1 << ", use count(p1): " << p1.use_count() << endl;
    if (p2) {
        cout << "p2: " << *p2 << ", use count(p2): " << p2.use_count() << endl;
    } else {
        cout << "p2 does not point to any object." << endl;
    }

    // Test for shared_ptr to point to objects
    shared_ptr<TestObj> p3 = make_shared<TestObj>(TestObj("Hello"));
    shared_ptr<TestObj> p4(new TestObj("World"));
    *p3 = *p3 + *p4;
    cout << "p3: " << p3->getValue() << ", use count of p3: " << p3.use_count() << endl;
    cout << "p4: " << (*p4).getValue() << ", use count of p4: " << p4.use_count() << endl;

    // unique_ptr test
    unique_ptr<TestObj> p5(new TestObj("Good morning"));
    cout << "p5: " << p5->getValue() << endl;
    unique_ptr<TestObj> p6(new TestObj("Go to school"));
    cout << "p6: " << p6->getValue() << endl;
    p6.reset(p5.release());
    if (!p5) {
        cout << "p5 does not point to any object." << endl;
    }
    cout << "p6: " << p6->getValue() << endl;

    // Test deleter
    auto testDeleter = [](TestObj *o) -> void { 
        cout << "Delete object: " << o->getValue() << endl;
        delete o;
    };
    shared_ptr<TestObj> p7(new TestObj("Show me the money"), testDeleter);
    cout << "p7: " << (*p7).getValue() << endl;
}

void SmartPointerTest::stop() {
    cout << "<<< SmartPointerTest" << endl;
}