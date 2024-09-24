#include<iostream>
using namespace std;

//creation of node
class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
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

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* forth = new Node(50);
    Node* fifth = new Node(60);

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    cout<<"Printing Linked list: "<<endl;
    print(first);

}