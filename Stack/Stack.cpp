#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;

class Stack {
private:
    int arr[MAX_SIZE]; // Defining an array for a queue
    int top;

public:
    Stack() { // constractor
        top = -1;
    }

    bool isEmpty() { // check if the stack is empty 
        return top == -1;
    }

    bool isFull() { // check if the stack is full 
        return top == MAX_SIZE - 1;
    }

    void push(int x) {  // the operation of adding to the stack
        if (isFull()) {
            cout << "Error, stack is full !" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed in stack" << endl;
    }

    int pop() { // the operation of removing from the stack
        if (isEmpty()) {
            cout << "Error, stack is empty !" << endl;
        }
        int x = arr[top--];
        return x;
    }

    int peek() { // show the last element of the stack
        if (isEmpty()) {
            cout << "Error, stack is empty !" << endl;
        }
        return arr[top];
    }
};