#include <iostream>
#include <string>
#include <string.h>
#include "CStringTest.h"

using namespace std;

#define BUFFER_LENGTH 128

static void strOperationTest() {
    cout << "=== str operations ===" << endl;

    size_t buffer_size = BUFFER_LENGTH * sizeof(char);

    string cppStr = "C++ cstring test";
    const char *cstr = cppStr.c_str();
    char *buffer = (char *) malloc(buffer_size);
    memset(buffer, 0, buffer_size);

    strncpy(buffer, cstr, 8);
    cout << "strncpy from \"" << cstr << "\" with length 8: " << buffer << endl;

    strcat(buffer, ", 123");
    cout << "strcat buffer with \"123\": " << buffer << endl;

    char a[] = "1111";
    char b[] = "222";
    memset(buffer, 0, buffer_size);
    strncpy(buffer, a, strlen(a));
    cout << "a: " << a << ", b: " << b << ", buffer: " << buffer << endl;
    cout << "Is a equals to b ? " << (strcmp(a, b) == 0 ? "Yes" : "No")  << " (" << strcmp(a, b) << ")" << endl;
    cout << "Is a equals to buffer ? " << (strcmp(a, buffer) == 0 ? "Yes" : "No") << " (" << strcmp(a, buffer) << ")" << endl;

    free(buffer);
}

static void pathTest(const char *path) {
    cout << "=== Path handling ===" << endl;

    size_t buffer_size = BUFFER_LENGTH * sizeof(char);
    char *buffer = (char *) malloc(buffer_size);

    memset(buffer, 0, buffer_size);
    strncpy(buffer, path, strlen(path));

    // p is pointed to the last occurence of '/'
    char *p = strrchr(buffer, '/');
    cout << "file name: " << (p + 1) << endl;  // "base.apk"
    size_t dir_length = p - buffer;

    char *buffer2 = (char *) malloc(buffer_size);
    strncpy(buffer2, path, dir_length);
    cout << "dir: " << buffer2 << endl;  // "/data/priv-app/contacts
    
    free(buffer);
    free(buffer2);
}

void CStringTest::start() {
    cout << ">>> CStringTest" << endl;
    strOperationTest();
    pathTest("/data/priv-app/contacts/base.apk");
}

void CStringTest::stop() {
    cout << "<<< CStringTest" << endl;
}
