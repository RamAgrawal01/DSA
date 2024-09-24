#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;

    }
    Node(int data){
        this->data = data;
        this->prev=NULL;
        this->next=NULL;
    }
};

int getLength(Node* &head){
    int len =0;
    Node* temp = head;

    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data <<" " ;
        temp=temp->next;
    }
}

//INSERT AT HEAD: //o(1);
void insertAtHead(Node* &head ,  Node* &tail , int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

//INSERT AT TAIL 
void insertAtTail(Node* &head ,  Node* &tail , int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail=newNode;
}

//INSERT AT POSITION
void insertAtPosition(Node* &head , Node* &tail , int data , int position){
      if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position==1){
        insertAtHead(head , tail , data);
        return;
    }
    int len = getLength(head);
    if(position >= len){
        insertAtTail(head , tail , data);
    }
    int i = 1;
    Node* prevNode = head;
    while(i<position-1){
        prevNode = prevNode->next;
        i++;
    }
    Node* currNode = prevNode->next;

    Node* newNode  = new Node(data);
    prevNode->next = newNode;
    newNode->prev = prevNode;
    currNode->prev=newNode;
    newNode->next = currNode;
}

//DELETION
void deleteAtHead(Node* &head , Node* &tail , int position ){

    if(head==NULL){
        cout<<"Linked list is empty";
        return;
    }
    if(head->next==NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if(position==1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);
    if(position==len){
        //delete last node
       Node* temp = tail;
       tail = tail->prev;
       temp->prev = NULL;
       tail->next = NULL;
       delete temp;
       return;
    }

    //delete at specified position
    int i =1;
    Node* left = head;
    while(i<position-1){
        left = left->next;
        i++;
    }
    Node* current = left->next;
    Node* right = current->next;

    //steps
    left->next = right;
    right->prev = left;
    current->prev=NULL;
    current->next =NULL;
    delete current;

}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = first;
    Node* tail = third;
    first->next = second;
    second->prev = first;

    second->next=third;
    third->prev = second;

    print(first);
    cout<<endl;
    insertAtHead(head , tail , 101);
    cout<<"Adding after head: "<<endl;
    print(head);
    cout<<endl;
    cout<<"Adding after tail: "<<endl;
    insertAtTail(head , tail , 102);
    print(head);
     cout<<endl;
     cout<<"Adding at specified position: "<<endl;
    insertAtPosition(head , tail , 301,3);
    print(head);
    cout<<endl;
     cout<<"Delete at head: "<<endl;
    deleteAtHead(head , tail , 1);
    print(head);
     cout<<endl;
     cout<<"Delete at Tail: "<<endl;
    deleteAtHead(head , tail , 5);
    print(head);
     cout<<endl;
     cout<<"Delete at specified: "<<endl;
    deleteAtHead(head , tail , 3);
    print(head);

    return 0;

}