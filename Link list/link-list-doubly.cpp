#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class linklist {
private:
    Node* head; // first node
    Node* tail; // last node
    int size;

public:
    linklist() : head(nullptr), tail(nullptr), size(0) {} // Constractor

    void insertAtIndex(int index, int data) { // // add a node at the desired index
        Node* new_node = new Node(data);

        if (index == 0) {
            if (!head) {
                head = new_node;
                tail = new_node;
            }
            else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
        else if (index == size) {
            new_node->prev = tail;
            if (tail) {
                tail->next = new_node;
            }
            tail = new_node;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next) {
                current->next->prev = new_node;
            }
            current->next = new_node;
        }
        size++;
    }

    void insertAtBegin(int data) { // Add to the beginning of a linked list
        insertAtIndex(0, data);
    }

    void insertAtEnd(int data) {  // Add to the end of a linked list
        insertAtIndex(size, data);
    }

    void updateNode(int index, int data) { // update link list
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = data;
    }

    int removeNodeAtIndex(int index) {  // delete the node with the given index.
        int data;
        if (size == 1) {
            data = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else if (index == 0) {
            data = head->data;
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        else if (index == size - 1) {
            data = tail->data;
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            data = current->data;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }

        size--;
        return data;
    }

    int removeNodeAtBegin() { // Delete the first node of a linked list
        return removeNodeAtIndex(0);
    }

    int removeNodeAtEnd() { // Delete the last node of a linked list
        return removeNodeAtIndex(size - 1);
    }

    int sizeOfList() const { // show the number of elements in a linked list
        return size;
    }

    void invert() { // Reverse link list
        Node* current = head;
        Node* temp = nullptr;
        tail = head;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }

    void concatenate(linklist& linked_list) { // Joining two linked lists together
        if (!head) {
            head = linked_list.head;
            tail = linked_list.tail;
        }
        else {
            tail->next = linked_list.head;
            if (linked_list.head) {
                linked_list.head->prev = tail;
            }
            tail = linked_list.tail;
        }
        size += linked_list.size;
    }

    void display() { //show link list
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};