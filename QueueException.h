#ifndef QUEUEEXCEPTION_h
#define QUEUEEXCEPTION_h

#include <cstring>
#include <iostream>
using namespace std;

class QueueException {
private:
    string errorMessage;
public:
    QueueException(string error = "NULL") {
        errorMessage = error;
    }
    void printError() {
        cout << errorMessage;
    }
};

#endif
