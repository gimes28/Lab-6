#ifndef STACKEXCEPTION_h
#define STACKEXCEPTION_h

#include <cstring>
#include <iostream>
using namespace std;

class StackException {
private:
    string errorMessage;
public:
    StackException(string error = "NULL") {
        errorMessage = error;
    }
    void printError() {
        cout << errorMessage;
    }
};

#endif
