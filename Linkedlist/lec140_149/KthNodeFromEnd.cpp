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

int KthNodeFromEnd(Node* &head, int k) {
    // Reverse the linked list
    head = reverse(head);

    int count = 1;
    Node* curr = head;

    // Traverse the reversed list
    while (curr != nullptr) {
        if (count == k) {
            return curr->data;
        }
        curr = curr->next;
        count++;
    }

    // If k is greater than the number of nodes, return -1
    return -1;
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
    int output=KthNodeFromEnd(head , 7);
    cout<<endl;
    cout<<"Output is: "<<output;
}