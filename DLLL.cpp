#include <iostream>
#include <string>
using namespace std;

struct Student {
    int ID;
    string name;
    string major;
};

class Node {
public:
    Student data;
    Node* next;
    Node(int id, string n, string m) {
        data.ID = id;
        data.name = n;
        data.major = m;
        next = nullptr;
    }
};

class StudentList {
private:
    Node* head;
public:
    StudentList() { head = nullptr; }

    void insertAtEnd(int ID, string name, string major) {
        Node* newNode = new Node(ID, name, major);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool deleteAtEnd() {
        if (head == nullptr) return false;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return true;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return true;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data.ID << " " << temp->data.name << " " << temp->data.major << endl;
            temp = temp->next;
        }
    }
};

int main() {
    StudentList list;
    list.insertAtEnd(101, "Cheat", "Computer Science");
    list.insertAtEnd(102, "Thyvan", "Computer Science");
    list.insertAtEnd(103, "Panha", "Computer Science");
    
    cout << "Before:" << endl;
    list.display();
    
    list.deleteAtEnd();
    
    cout << "After:" << endl;
    list.display();
    
    return 0;
}