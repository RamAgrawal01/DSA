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
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int length(Node* &head){
    
    Node* slow= head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow =slow->next;
        }
        if(slow==fast){
            int loopLength = 1;
            Node* temp = slow;
            while(temp->next != slow){
                loopLength++;
                temp=temp->next;
            }
            return loopLength;
        }
    }
    return 0;


}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eigth = new Node(80);
    Node* nine = new Node(90);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next=eigth;
    eigth->next = nine;
    nine->next = fifth;

    cout<<"Loop is present or not: "<<length(head);
    return 0;
}