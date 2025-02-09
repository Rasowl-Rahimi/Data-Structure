#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        data = d;
        prev = next = this;
    }
};

class clist {
private:
    Node* head;
    int size;

public:
    clist() {
        head = nullptr;
        size = 0;
    }

    void insertAtIndex(int data, int index) { // add a node at the desired index
        if (index < 0 || index > size) {
            cout << "Error" << endl;
            return;
        }

        Node* newNode = new Node(data);
        if (index == 0) {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
        }
        size++;
    }

    void insertatend(int data) { // Add to the end of a linked list
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            newNode->prev = head->prev;
            newNode->next = head;
            head->prev->next = newNode;
            head->prev = newNode;
        }
        size++;
    }

    void insertatbegin(int data) { // Add to the beginning of a linked list
        Node* newNode = new Node(data);
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
        size++;
    }

    void updateNode(int data, int index) { // Update link list
        if (index < 0 || index >= size) {
            cout << "Error" << endl;
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = data;
    }

    int removenodeatIndex(int index) { // Delete the node with the given index.
        if (index < 0 || index >= size) {
            cout << "Error" << endl;
            return -1;
        }

        Node* current = head;
        if (index == 0) {
            head = head->next;
            head->prev->next = head;
            head->prev = head->prev->prev;
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            nodeToDelete->next->prev = current;
            delete nodeToDelete;
        }
        size--;
        return 0;
    }

    int removeNodeAtEnd() { // Delete the last node of a linked list
        if (head == nullptr) {
            return -1;
        }
        Node* temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        delete temp;
        size--;
        return 0;
    }

    int removeNodeAtBegin() { // Delete the first node of a linked list
        if (head == nullptr) {
            return -1;
        }
        Node* temp = head;
        head = head->next;
        head->prev = temp->prev;
        temp->prev->next = head;
        delete temp;
        size--;
        return 0;
    }

    int sizeOfList() { // show the number of elements in a linked list
        return size;
    }

    void Display() { // Show link list
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
    void reverse() { // Reverse link list
        if (head == nullptr) {
            return;
        }

        Node* current = head;
        do {

            Node* temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        } while (current != head);

        head = head->prev;
    }
};