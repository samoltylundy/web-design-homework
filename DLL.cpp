#include<iostream>
using namespace std;

class DoublyNode {
public:
    int data;
    DoublyNode* next;
    DoublyNode* previous;
    DoublyNode(int value) { 
        data = value; 
        next = nullptr; 
        previous = nullptr; 
    }
};

class DoublyLinkedList {
public:
    DoublyNode* head, *tail;
    DoublyLinkedList() { 
        head = nullptr; 
        tail = nullptr;
    }

    void add(int value) {
        DoublyNode *mynewNode = new DoublyNode(value);
        if (head == nullptr) {
            head = mynewNode;
            tail = mynewNode;
        } else {
            // Make connection
            tail->next = mynewNode;
            mynewNode->previous = tail;
            tail = mynewNode;  // Update tail
        }
    }

    void displayForward() {
        DoublyNode *t = head;
        while (t != nullptr) {
            cout << t->data;
            if (t->next != nullptr) cout << " <-> ";
            t = t->next;
        }
        cout << " -> NULL\n";
    }

    void displayBackward() {
        if (head == nullptr) return;
        DoublyNode *t = tail;
        while (t != nullptr) {
            cout << t->data;
            if (t->previous != nullptr) cout << " <-> ";
            t = t->previous;
        }
        cout << " -> NULL\n";
    }

    // Exercise 3: Insert at beginning
    void insertAtBeginning(int value) {
        DoublyNode* newNode = new DoublyNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }

    // Exercise 4: Delete last node
    void deleteLast() {
        if (tail == nullptr) return;
        
        if (head == tail) { // Only one node
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            DoublyNode* temp = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete temp;
        }
    }
};