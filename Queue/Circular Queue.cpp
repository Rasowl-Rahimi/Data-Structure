#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;

class circularqueue {
private:
    int arr[MAX_SIZE]; // Defining an array for a queue
    int front;
    int rear;

public:
    circularqueue() { // constractor
        front = -1;
        rear = -1;
    }

    bool isEmpty() { // check if the queue is empty 
        return front == -1 && rear == -1;
    }

    bool isFull() { // check if the queue is full
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int x) { // add to queue
        if (isFull()) {
            cout << "Erorr,Queue is full !";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE; 
        }
        arr[rear] = x;
    }

    int dequeue() { // remove from queue
        if (isEmpty()) {
            cout << "Erorr empty";
            return -1;
        }
        int x = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
        return x;
    }

    int Peek() { // show the first element of the queue
        if (isEmpty()) {
            cout << "Erorr empty";
            return -1;
        }
        else {
            return arr[front];
        }
    }
    void display() { // display the queue
        if (isEmpty()) {
            cout << "Erorr full";
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};