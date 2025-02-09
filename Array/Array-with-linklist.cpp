#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class linklist {
private:
    Node* head;
    int size;

public:
    linklist() : head(nullptr), size(0) {} // Constractor

    void append(int value) { // The operation of adding to the end of a linked list.
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    int get(int index) { // Get the value of the given index.
        if (index < 0 || index >= size) {
            cout << "Error, The desired index is not correct.";
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void set(int index, int value) { // Substitute the new value into the given node.
        if (index < 0 || index >= size) {
            cout << "Error, The desired index is not correct.";
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = value;
    }

    int getSize() const { // Show size
        return size;
    }

    void display() const { // display the linklist
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Array {
private:
    linklist list;

public:
    void add(int value) {
        list.append(value);
    }

    int get(int index) {
        return list.get(index);
    }

    void set(int index, int value) {
        list.set(index, value);
    }

    int size() {
        return list.getSize();
    }

    void display() {
        list.display();
    }
};