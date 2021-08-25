#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include "MapTest.h"

using namespace std;

static void mapTest() {
    /* -- Types of Map -- */
    /**
     * map<int, string>::key_type keyType;         // keyType is an int
     * map<int, string>::value_type valueType;     // valueType is a pair<int, string>
     * map<int, string>::mapped_type mappedType;   // mappedType is a string
     */

    vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
    vector<string> s = { "one", "two", "three", "four", "five",
                         "six", "seven", "eight", "nine", "ten" };
    /* -- Map -- */
    map<int, string> m;
    auto i = v.cbegin();
    auto e = s.cbegin();
    for (; i != v.cend() || e != s.cend(); i++, e++) {
        m.insert({ *i, *e });
    }

    // Another way to initialize map
    // map<int, string> m = {
    //     { 1, "one" }, { 2, "two" }, { 3, "three" }, { 4, "four" }, { 5, "five" },
    //     { 6, "six" }, { 7, "seven" }, { 8, "eight" }, { 9, "nine" }, { 10, "ten" },
    // };

    m.insert(make_pair(11, "eleven"));

    cout << "map: " << endl;
    for (auto p : m) {
        cout << "(" << p.first << ", " << p.second << "); ";
    }
    cout << endl;

    auto f = m.find(8);
    if (f != m.end()) {
        cout << "The content of key '8' in map is: " << (*f).first << ", " << (*f).second << endl;
    } else {
        cout << "Not found '8' in map" << endl;
    }

    /* -- Unordered Map -- */
    unordered_map<int, string> m2;
    auto i2 = v.cbegin();
    auto e2 = s.cbegin();
    for (; i2 != v.cend() || e2 != s.cend(); i2++, e2++) {
        m2.insert({ *i2, *e2 });
    }
 
    cout << "Unordered map: " << endl;
    for (auto p = m2.cbegin(); p != m2.cend(); p++) {
        cout << "(" << (*p).first << ", " << (*p).second << "); ";
    }
    cout << endl;

    auto f2 = m.find(12);
    if (f2 != m.end()) {
        cout << "The content of key '8' in map2 is: " << (*f2).first << ", " << (*f2).second << endl;
    } else {
        cout << "Not found '12' in map2" << endl;
    }
}

void MapTest::start() {
    cout << ">>> MapTest" << endl;
    mapTest();
}

void MapTest::stop() {
    cout << "<<< MapTest" << endl;
}