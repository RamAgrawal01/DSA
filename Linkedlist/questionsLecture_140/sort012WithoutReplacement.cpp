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

Node* sort012(Node* &head){
    
    //create dummy node
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //traverse the original LL
    Node* curr = head;
  while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        temp->next = NULL;

        if (temp->data == 0) {
            zeroTail->next = temp;
            zeroTail = temp;
        } else if (temp->data == 1) {
            oneTail->next = temp;
            oneTail = temp;
        } else if (temp->data == 2) {
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    //all three ar ready joun them


    //Modify list of one(delete dummy node)
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    //Modify list of two(delete dummy node)
     temp =twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    //join list
    if(oneHead!=NULL){
        //one wali list not empty
        zeroTail->next = oneHead;
        if(twoHead!=NULL){
            oneTail->next = twoHead;
        }
    }
    else{
        //one wali list empty
        if(twoHead!=NULL){
            zeroTail->next=twoHead;
        }
    }
    //remove zero head
    temp = zeroHead;
    zeroHead=zeroHead->next;
    temp->next = NULL;
    delete temp;

    //return
    return zeroHead;
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(0);
    Node* fifth = new Node(0);
    Node* sixth = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next =  sixth;
    sixth->next = NULL;

    print(head);
    cout<<endl;
    head =sort012(head);
    print(head);
}