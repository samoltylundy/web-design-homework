#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int value){
        data=value;
        next=nullptr;
    }
};

class sll{
    private:
    node* head;
    node* tail;
    public:
    sll(){
        head=nullptr;
        tail=nullptr;
    }

    void end(int value){
        node* newNode= new node(value);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void print(){
        node* temp= head;
        while(temp!=nullptr){
            cout<<temp->data;
            temp=temp->next;
        }
    }
    
    
};

int main(){
    sll s1;
    s1.end(2);
    s1.end(3);
    s1.end(4);
    s1.print();

    return 0;
}
