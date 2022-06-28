#include <iostream>
#include <string>
#include <vector>
#include "StringTest.h"

using namespace std;

// Leetcode - Medium - 151. Reverse Words in a String
class ReverseWords {
private:
    vector<string> split(string s) {
        vector<string> strs;
        string tmp;
        for (int i = 0 ; i < s.length(); i++) {
            if (s[i] != ' ') {
                tmp += s[i];
            } else if (!tmp.empty()) {
                strs.push_back(tmp);
                tmp.clear();
            }
        }
        if (!tmp.empty()) {
            strs.push_back(tmp);
        }
        return strs;
    }
public:
    string reverseWords(string s) {
        vector<string> substrings = split(s);
        //cout << "substrings count: " << substrings.size() << endl;
        string ret;
        for (int i = substrings.size() - 1; i >= 0; i--) {
            if (i == substrings.size() - 1) {
                ret = substrings[substrings.size() - 1];
            } else {
                ret += ' ';
                ret += substrings[i];
            }
        }
        return ret;
    }
};

void StringTest::start() {
    cout << ">>> StringTest" << endl;

    cout << "=== Leetcode - Medium - 151. Reverse Words in a String ===" << endl;
    string test = "  English is a West    Germanic language originally spoken   by the inhabitants of    early  medieval England";
    cout << "The original string: " << test << endl;

    ReverseWords obj;
    string reversed = obj.reverseWords(test);

    cout << "The reversed words of test string: " << reversed << endl;

    cout << "=== String Operations ===" << endl;
    string a("123");
    string b("456");
    string c ;
    cout << "string a: " << a << ", string b: " << b << endl;
    c = a + b;
    cout << "string a + b: " << c << endl;
    
    cout << "Is a equals to b ? " << ((a == b) ? "True" : "False") << endl;
    cout << "Is a equals to \"123\" ? " << ((a == "123") ? "True" : "False") << endl;

    a.append("A");
    cout << "Append 'A' to a: " << a << endl;

    a.replace(1, 1, "abc");
    cout << "Replace '2' with \"abc\" in string a: " << a << endl;

    char buffer[100] = { 0 };
    a.copy(buffer, 4, 1);
    cout << "Copy substring of a from index 1 with length 4 to buffer: " << buffer << endl;
}

void StringTest::stop() {
    cout << "<<< StringTest" << endl;
}