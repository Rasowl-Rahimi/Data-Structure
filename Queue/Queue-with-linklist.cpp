#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queuewll {
private:
    Node* front;
    Node* rear;

public:
    Queuewll() { // Constractor
        front = rear = nullptr;
    }

    void enqueue(int x) { // add to queue
        Node* temp = new Node();
        temp->data = x;
        temp->next = nullptr;

        if (rear == nullptr) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() { // remove from queue
        if (front == nullptr) {
            cout << "Error, Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void display() { // Display the Queue
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};