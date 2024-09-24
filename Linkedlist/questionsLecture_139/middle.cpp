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
Node* getMiddle(Node* head){
    if(head == NULL){
        cout<<"Linked list is empty";
        return head;
    }
    if(head->next==NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL){
        fast = fast->next; //ek hi step badya
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}


int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    cout << "Original Linked list: ";
    print(head);
    cout<<endl;
    cout<<"Middle node is: "<<getMiddle(head)->data<<endl;
}