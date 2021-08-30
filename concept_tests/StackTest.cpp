#include <iostream>
#include <stack>
#include "StackTest.h"

using namespace std;

static void stackTest() {
    stack<int> stk;

    cout << "[START] Size of stk: " << stk.size() << endl;

    // push to stack
    stk.push(5);
    stk.push(2);
    stk.push(7);
    int tmp = stk.top();
    stk.pop();
    cout << "Pop " << tmp << endl;
    stk.push(9);
    stk.push(6);

    cout << "[BEFORE POP] Size of stk: " << stk.size() << endl;

    // pop
    int count = 0;
    while (!stk.empty()) {
        int i = stk.top(); // Get the next element in queue (Not Removed)
        cout << "The top of element: " << i << endl;
        stk.pop(); // Remove the next element in queue
    }

    cout << "[END] Size of stk: " << stk.size() << endl;
}

void StackTest::start() {
    cout << ">>> StackTest" << endl;
    stackTest();
}

void StackTest::stop() {
    cout << "<<< StackTest" << endl;
}