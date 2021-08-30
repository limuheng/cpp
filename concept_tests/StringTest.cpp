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
    string test = "  English is a West    Germanic language originally spoken   by the inhabitants of    early  medieval England";
    cout << "The original string: " << test << endl;

    ReverseWords obj;
    string reversed = obj.reverseWords(test);

    cout << "The reversed words of test string: " << reversed << endl;
}

void StringTest::stop() {
    cout << "<<< StringTest" << endl;
}