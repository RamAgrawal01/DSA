#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    
    }
};

 void insertAtPosition(int position,Node* &head , Node* &tail , int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    
    //find the position
    int i =1;
    Node* prev = head;
    while(i<position){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    //creation of new node
    Node* newNode = new Node(data);
    //join newNode to curr Node
    newNode->next = curr;
    //join newNode to prev Node
    prev->next = newNode;
}

int main(){
    Node* head = new Node(10);
    Node* tail = NULL;
    // insertAtPosition(head , tail , 20);
}

