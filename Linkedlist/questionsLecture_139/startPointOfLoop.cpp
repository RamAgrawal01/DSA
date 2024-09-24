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
int startingPoint(Node* &head){
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
        return -1;
    }

    //now find the position
    slow = head;
    int slowCount =0;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
        slowCount++;
    }
    return slowCount;
}

int main(){
    Node* head = new Node(3);
    Node* second = new Node(2);
    Node* third = new Node(0);
    Node* fourth = new Node(-4);
    // Node* fifth = new Node(50);
    // Node* sixth = new Node(60);
    // Node* seventh = new Node(70);
    // Node* eigth = new Node(80);
    // Node* nine = new Node(90);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;
    // fifth->next = sixth;
    // sixth->next = seventh;
    // seventh->next=eigth;
    // eigth->next = nine;
    // nine->next = fifth;

    cout<<"Loop is present or not: "<<startingPoint(head);
    return 0;
}