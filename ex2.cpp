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

    void insertAtBeginning(int ID, string name, string major) {
        Node* newNode = new Node(ID, name, major);
        newNode->next = head;
        head = newNode;
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
    list.insertAtBeginning(101, "Cheat", "Computer Science");
    list.insertAtBeginning(102, "Thyvan", "Computer Science");
    list.insertAtBeginning(103, "Panha", "Computer Science");
    list.display();
    return 0;
}