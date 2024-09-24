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
Node*  removeLoop(Node* &head){
    //check for looop
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast){
            break;
        }
    }
    // No cycle detected
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }

    

    //now find the position
    slow = head;
    Node* prev = NULL;
    while(slow!=fast){
        prev = fast;
        slow=slow->next;
        fast=fast->next;
        
    }
    //find the last node in the loop
    if(prev!=NULL){
        while(fast->next !=slow){
            fast = fast->next;
        }
        ///remove joint
        fast->next = NULL;
    }
    return head;
}
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
 Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    // Creating a loop for testing purposes
    ninth->next = fourth; // Create a loop back to fourth node

    head =removeLoop(head);
    print(head);
    return 0;
}