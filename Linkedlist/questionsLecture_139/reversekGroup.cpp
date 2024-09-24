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

int getLength(Node* &head){
    int len =0;
    Node* temp = head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    // cout<<"Length of linked list is: "<<len<<endl;
    return len;
}

Node* reverseKNodes(Node* &head , int k){

    if(head==NULL){
        cout<<"Linked list is empty";
        return NULL;
    }

    int len = getLength(head);

    //if k is greater than number of nodes in linked list
    if(k>len){
        return head;
    }

    //it means number of node in LL =>K;

    //reverse first K nodes of LL
    Node* prev = NULL;
    Node* curr = head;
    Node* temp = NULL;
    int count =0;

    while (count < k && curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }

    //check if nodes are k nods
    if(temp!=NULL){
       head->next= reverseKNodes(temp , k);
    }

    return prev;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    // head->next->next->next->next->next = new Node(60);

    cout << "Original Linked list: ";
    print(head);
    cout<<endl;
    cout<<"After reversing K groups: ";
    head=reverseKNodes(head,3);
    print(head);

}