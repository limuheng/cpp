#include <algorithm>
#include <iostream>
#include <vector>
#include "FunctionPointerTest.h"

using namespace std;

static void countAndSay(void (*callback)(int), int max, int step) {
    for (int i = 0; i <= max; i++) {
        if ((i != 0) && (i % step == 0)) {
            callback(i);
        }
    }
}

static void countCallback(int num) {
    cout << "NUM: " << num << endl;
}

static bool isGreaterThan(const int &a, const int &b) {
    return a > b;
}

void FunctionPointerTest::start() {
    cout << ">>> FunctionPointerTest" << endl;
    cout << "Count to 100" << endl;
    countAndSay(countCallback, 100, 20);
    cout << "Count to 300" << endl;
    countAndSay(countCallback, 300, 60);

    vector<int> v = { 5, 2, 9, 4, 6, 8 };
    sort(v.begin(), v.end(), isGreaterThan);
    cout << "vector after sorted: ";
    for (auto it = v.cbegin(); it != v.cend(); it++) {
        if (it == v.cbegin()) {
            cout << *it;
        } else {
            cout << ", " << *it;
        }
    }
    cout << endl;
}

void FunctionPointerTest::stop() {
    cout << "<<< FunctionPointerTest" << endl;
}
