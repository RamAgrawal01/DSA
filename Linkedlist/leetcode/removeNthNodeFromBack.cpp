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

Node* reverse(Node* &head){

    Node* prev = NULL;
    Node* temp = NULL;
    Node* curr = head;

    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    print(prev);
    return prev;

}

Node* removeKthNodeFromEnd(Node* &head , int k){

    Node* slow = head;
    Node* fast = head;

    //iterate the fast pointer to the Kth node from starting
    for(int i =0 ; i<k ; i++){
        fast = fast->next; //fast is exactly at the kth node

    }

    //if Kth node is the last node from back , it means remove head node
    if(fast==NULL){
        return head->next;
    }

    
    while(fast->next !=NULL){
        fast = fast->next;
        slow = slow->next; // slow is at the (k-1)th node from back
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delNode->next = NULL;
    delete delNode;
    
    //return head
    return head;
}


int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(5);
    Node* fifth = new Node(6);
    // Node* sixth = new Node(4);
    // Node* seventh = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next =  NULL;
    

    print(head);
    cout<<endl;
    Node* output=removeKthNodeFromEnd(head , 3);
    cout<<endl;
    print(output);
}

