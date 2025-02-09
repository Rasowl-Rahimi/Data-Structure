#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;

    node(int d) {
        data = d;
        next = nullptr;
    }
};

class Stack {
private:
    node* top;

public:
    Stack() { // Constractor
        top = nullptr;
    }

    void push(int data) { // Add to stack
        node* newNode = new node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() { // Remove from stack
        int data = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() { // show the last element of the stack
        return top->data;
    }

    bool isEmpty() { // check if the stack is empty 
        return top == nullptr;
    }

    void Display() { // Display the Stack
        node* temp = top;
        while (top != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};