#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() { // constractor
        head = nullptr;
        size = 0;
    }

    void InsertAtIndex(int data, int index) { // add a node at the desired index
        if (index < 0 || index > size) {
            cout << "Error, The desired index is not correct.";
        }

        Node* newnode = new Node(data); // defining a new node and allocating space to it

        if (index == 0) { 
            newnode->next = head;
            head = newnode;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
        size++;
    }

    void InsertAtEnd(int data) { // Add to the end of a linked list
        InsertAtIndex(data, size);
    }

    void InsertAtBegin(int data) { // Add to the beginning of a linked list
        InsertAtIndex(data, 0);
    }

    void UpdateNode(int data, int index) { // update link list
        if (index < 0 || index >= size) {
            cout << "Error, The desired index is not correct.";
        }

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = data;
    }

    int RemoveNodeAtIndex(int index) { // delete the node with the given index.

        Node* removedNode;
        int removedData;

        if (index == 0) {
            removedNode = head;
            head = head->next;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            removedNode = current->next;
            current->next = removedNode->next;
        }

        removedData = removedNode->data;
        delete removedNode;
        size--;
        return removedData;
    }

    int RemoveNodeAtEnd() { // Delete the last node of a linked list
        return RemoveNodeAtIndex(size - 1);
    }

    int RemoveNodeAtBegin() { // Delete the first node of a linked list
        return RemoveNodeAtIndex(0);
    }

    int SizeOfList() {  // show the number of elements in a linked list
        return size;
    }

    void Concatenate(LinkedList& other) { // Joining two linked lists together
        Node* current = other.head;
        while (current != nullptr) {
            InsertAtEnd(current->data);
            current = current->next;
        }
    }

    void Display() { // show the link list
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
    void invert() { // Reverse linked list
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};