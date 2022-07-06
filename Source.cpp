#include <iostream>
#include <fstream>
#include "Stack.h"
#include "Queue.h"

int main() {
    //input file fstream object
    fstream textFile;
    //current word in input
    string word;
    //total number of words in the file
    int words = 0;
    //open file
    textFile.open("stringfile.txt", ios::in);

    ifstream file("stringfile.txt");

    //Counts words
    while (textFile >> word) {
        words++;
    }

    //this queue will hold the reversed words
    Queue<string> stringQueue(words);

    //reset the file to be read again
    textFile.close();
    textFile.open("stringfile.txt", ios::in);

    while (textFile >> word) {
        //each iteration, create a stack for the word, push chars to it, then pop the chars and reappend to thisWord string. Then enqueue thisWord
        Stack<char> charStack(word.length());
        string thisWord = "";
        for (int i = 0; i < word.length(); i++) {
            char* app = new char(word.at(i));
            try {
                charStack.push(app);
            }
            catch (StackException e) {
                e.printError();
            }
        }

        for (int i = 0; i < word.length(); i++) {
            try {
                thisWord += *charStack.pop();
            }
            catch (StackException e) {
                e.printError();
            }
        }
        string* newString = new string(thisWord);
        try {
            stringQueue.Enqueue(newString);
        }
        catch (QueueException q) {
            q.printError();
        }
    }

    int len = stringQueue.Length();

    //prints out the reversed words in stringQueue
    for (int i = 0; i < len; i++) {
        try {
            cout << *stringQueue.Dequeue() << " ";
        }
        catch (QueueException q) {
            q.printError();
        }
    }

}