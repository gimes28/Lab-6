#ifndef QUEUE_h
#define QUEUE_h

#include <iostream>
#include "QueueException.h"

// Queue Class of type Template
template<class Q>
class Queue {
private:
    Q** data;
    int length;
    int SIZE;
public:
    Queue(int);
    void Enqueue(Q* in);
    Q* Dequeue();
    Q* Peek();
    int Length();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
};

//Constructor
template<class Q>
Queue<Q>::Queue(int size) {
    data = new Q * [size];
    SIZE = size;
    length = 0;
}

// adds new items into the queue
template<class Q>
void Queue<Q>::Enqueue(Q* in) {
    if (isFull()) {
        throw QueueException("Queue Overflow");
    }
    data[length] = in;
    length++;
}

// removes items from the bottom of the queue
template<class Q>
Q* Queue<Q>::Dequeue() {
    if (isEmpty()) {
        throw QueueException("Queue Underflow");
    }
    Q* removed = data[0];
    for (int i = 0; i < length; i++) {
        data[i] = data[i + 1];
    }
    length--;
    return removed;
}

// displays item at the top of the queue
template<class Q>
Q* Queue<Q>::Peek() {
    if (isEmpty()) {
        throw QueueException("Queue is empty");
    }
    return data[0];
}

// returns if the queue is full
template<class Q>
bool Queue<Q>::isFull() {
    return length >= SIZE;
}

// returns if the queue is empty
template<class Q>
bool Queue<Q>::isEmpty() {
    return length <= 0;
}

// returns the length of the queue
template<class Q>
int Queue<Q>::Length() {
    return length;
}

// makes the queue empty
template<class Q>
void Queue<Q>::makeEmpty() {
    length = 0;
}

#endif
