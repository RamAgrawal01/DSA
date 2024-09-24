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

Node* removeDuplicateInSorted(Node* &head){
    if(head==NULL){
        return NULL;
    }
    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL){
        bool isDuplicate =false;

        //check if curr node has duplicate
        while(curr->next!=NULL && (curr->data == curr->next->data)){
            isDuplicate=true;
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }

        if(isDuplicate){
            if(prev==NULL){
                //the head iteself is a part of duplicate
                Node* temp = head;
                head = head->next;
                delete temp;
                curr = head;
            }
            else{
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        //if not duplicate
        else{
            prev = curr;
            curr=curr->next;
        }
    }
    return head;
    
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(1);
    Node* third = new Node(1);
    Node* fourth = new Node(2);
    Node* fifth = new Node(3);
    // Node* sixth = new Node(4);
    // Node* seventh = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next =  NULL;
    

    print(head);
    cout<<endl;
    Node* output=removeDuplicateInSorted(head);
    print(output);
}