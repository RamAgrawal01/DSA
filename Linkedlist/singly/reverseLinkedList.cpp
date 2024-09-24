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
        temp = temp->next;
    }
}
Node* reverseLinkedList(Node* &prev , Node* &curr){
    //base cse
    if(curr==NULL){
        //ll
        return prev;
    }
    //1 case solve
    Node* forward = curr->next;
    curr->next = prev;

    reverseLinkedList(curr,forward);
}

int main(){
     Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout<<"Original Linked list: ";
    print(head);
    cout<<endl;
    Node* prev = NULL;
    Node* curr = head;
    head=reverseLinkedList(prev,curr);
    cout<<"Reversed Linked list: ";
    print(head);
    
}