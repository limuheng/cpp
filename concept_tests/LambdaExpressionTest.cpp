#include <algorithm>
#include <iostream>
#include <vector>
#include "LambdaExpressionTest.h"

using namespace std;

void LambdaExpressionTest::start() {
    cout << ">>> LambdaExpressionTest" << endl;

    int multiplicand = 100;

    vector<int> list = { 3, 7, 2, 5, 12 };

    cout << endl << " -------------------------- " << endl;
    cout << "Explicit capture test: " << endl;
    auto multiply = [multiplicand] (int multiplier)
            -> void { cout <<  multiplicand * multiplier << " "; };

    for_each(list.begin(), list.end(), multiply);

    cout << endl << " -------------------------- " << endl;
    cout << "Implicit capture test: " << endl;
    auto multiply2 = [=] (int multiplier)
            -> void { cout << multiplicand * multiplier << " "; };

    for_each(list.begin(), list.end(), multiply2);

    cout << endl << " -------------------------- " << endl;
    cout << "Capture by reference test: " << endl;
    auto multiply3 = [&multiplicand] (int multiplier)
            -> void { cout << ++multiplicand * multiplier << " "; };

    for_each(list.begin(), list.end(), multiply3);
    cout << endl << "multiplicand= " << multiplicand;

    cout << endl << " -------------------------- " << endl;
    cout << "Pass by reference test: " << endl;
    multiplicand = 100;
    auto multiply4 = [=] (int &multiplier)
            -> void {
                multiplier += 1;
                cout << multiplicand * multiplier << " ";
            };

    for_each(list.begin(), list.end(), multiply4);

    cout << endl;
    for (int i = 0; i < list.size(); i++) {
        if (i > 0) {
            cout << ", " << list.at(i);
        } else {
            cout << list.at(i);
        }
    }
    cout << endl << " -------------------------- " << endl;
}

void LambdaExpressionTest::stop() {
    cout << "<<< LambdaExpressionTest" << endl;
}