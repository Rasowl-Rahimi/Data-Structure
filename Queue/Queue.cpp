#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class myqueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    myqueue() {   //constractor
        front = -1;
        rear = -1;
    }

    bool isEmpty() {  //check if the queue is empty 
        return front == -1 && rear == -1;
    }

    bool isFull() { //check if the queue is full
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int x) { // add to queue
        if (isFull()) {
            cout << "Erorr,Queue is full !" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
    }

    int dequeue() { // remove from queue
        if (isEmpty()) {
            cout << "Erorr,Queue is empty !" << endl;
            return -1;
        }
        int x = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
        return x;
    }

    int peek() { // show the first element of the queue
        if (isEmpty()) {
            cout << "Erorr,Queue is empty !" << endl;
            return -1;
        }
        return arr[front];
    }

    void reverseQueue() { // reverse the queue
        if (isEmpty())
            return;

        int temp;
        int start = front;
        int end = rear;

        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void display() { // display the queue
        if (isEmpty()) {
            cout << "Erorr,Queue is empty !" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};