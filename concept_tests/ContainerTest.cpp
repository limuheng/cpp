#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <array>
#include <map>
#include "ContainerTest.h"

using namespace std;

static void vectorTest() {
    cout << ">>> vectorTest" << endl;
    vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };

    cout << "Size of vector: " << v.size() << endl;
    cout << "Max size of vector: " << v.max_size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl;

    // 觀察 vector size 的增長情形
    vector<int> v2(10);
    cout << "Size of vector2: " << v2.size() << endl;
    cout << "Capacity of vector: " << v2.capacity() << endl;
    v2 = v;
    v2.push_back(10);
    cout << "Size of vector2: " << v2.size() << endl;
    cout << "Capacity of vector: " << v2.capacity() << endl;

    cout << "<<< vectorTest" << endl;
}

static void dequeTest() {
    cout << ">>> dequeTest" << endl;
    deque<int> dq = { 0,1,2,3,4,5,6,7,8,9 };

    cout << "<<< dequeTest" << endl;
}

static void stringTest() {
    cout << ">>> stringTest" << endl;
    string s = "Hello, world!";

    cout << "<<< stringTest" << endl;
}

static void arrayTest() {
    cout << ">>> arrayTest" << endl;
    array<int, 10> a = { 0,1,2,3,4,5,6,7,8,9 };

    for (auto i : a) {
        i++;
        cout << i << " ";
    }
    cout << endl;

    for (array<int, 10>::size_type i = 0; i < a.size(); i++) {
        cout << a.at(i) << " ";
    }
    cout << endl;

    cout << "<<< arrayTest" << endl;
}

static void mapTest() {
    cout << ">>> mapTest" << endl;
    vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
    vector<string> s = { "one", "two", "three", "four", "five",
                         "six", "seven", "eight", "nine", "ten" };
    map<int, string> m;

    auto i = v.cbegin();
    auto e = s.cbegin();
    for (; i != v.cend() || e != s.cend(); i++, e++) {
        m.insert({ *i, *e });
    }

    cout << "map: " << endl;
    for (auto p : m) {
        cout << "(" << p.first << ", " << p.second << "); ";
    }
    cout << endl;

    auto f = m.find(8);
    if (f != m.end()) {
        cout << "The content of key '8' in map is: " << (*f).first << ", " <<  (*f).second << endl;
    }

    cout << "<<< mapTest" << endl;
}

void ContainerTest::start() {
    cout << ">>> ContainerTest" << endl;
    vectorTest();
    arrayTest();
    mapTest();
}

void ContainerTest::stop() {
    cout << "<<< ContainerTest" << endl;
}