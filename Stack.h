#ifndef STACK_h
#define STACK_h

#include <iostream>
#include "StackException.h"

template<class T>
class Stack {
private:
    T** data;
    int length;
    int SIZE;
public:
    Stack(int);
    void push(T* val);
    T* pop();
    T* top();
    int Length();
    bool isFull();
    bool isEmpty();
    void makeEmpty();
};

template<class T>
Stack<T>::Stack(int size) {
    data = new T * [size];
    SIZE = size;
    length = 0;
}

template<class T>
void Stack<T>::push(T* val) {
    if (isFull()) {
        throw StackException("Stack Overflow");
    }
    data[length] = val;
    length++;
}

template<class T>
T* Stack<T>::pop() {
    if (isEmpty()) {
        throw StackException("Stack Underflow");
    }
    length--;
    return data[length];
}

template<class T>
T* Stack<T>::top() {
    if (isEmpty()) {
        throw StackException("Stack Overflow");
    }
    return data[length - 1];
}

template<class T>
bool Stack<T>::isEmpty() {
    return length <= 0;
}

template<class T>
bool Stack<T>::isFull() {
    return length >= SIZE;
}

template<class T>
int Stack<T>::Length() {
    return length;
}

template<class T>
void Stack<T>::makeEmpty() {
    while (length > 0) {
        length--;
        delete data[length];
    }
}

#endif
