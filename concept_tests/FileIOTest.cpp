#include <iostream>
#include <fstream>
#include <array>
#include "FileIOTest.h"

using namespace std;

#define ARRAY_SIZE 10

static array<string, ARRAY_SIZE> sTexts = {
        "Oil producers usually tame soaring prices by turning on the taps.",
        "Here's why that may not work this time",
        "Oil-consuming nations wait with bated breath as the OPEC cartel meets once again ",
        "this week to decide whether to pump more crude into the market to tame runaway prices.",
        "By Mohammed Abdelbary"
};

static void readFile() {
    cout << "=== readFile ===" << endl;
    ifstream ifs;
    // ifstream ifs("./test/read_file.txt");
    ifs.open("./test/read_file.txt");

    string buffer;

    while (ifs >> buffer) {
        cout << buffer << endl;
    }

    ifs.close();
}

static void writeFile() {
    cout << "=== writeFile ===" << endl;

    ofstream ofs;
    // ofstream ofs("./test/write_file.txt");
    ofs.open("./test/write_file.txt");
    
    for (auto i = sTexts.cbegin(); i != sTexts.cend(); i++) {
        if (!(*i).empty()) {
            ofs << (*i) << endl;
        }
    }

    ofs.close();
}

void FileIOTest::start() {
    cout << ">>> FileIOTest" << endl;
    readFile();
    writeFile();
}

void FileIOTest::stop() {
    cout << ">>> FileIOTest" << endl;
}