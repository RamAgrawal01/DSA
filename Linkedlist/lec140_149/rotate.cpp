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

int getLength(Node* head){
    int len =0;
    while(head!=nullptr){
        head= head->next;
        len++;
    }
    return len;
}

Node* rotateList(Node* &head , int k){

    if(head==nullptr || k==0) return head;
    int len = getLength(head);
    int actualK = k%len; 

    if(actualK==0) return head;

    //Find the new last node (in case of right LL : len-actualK-1)
    //(in case of left ll : actualK-1);
    int lastNodePos = actualK-1;
    Node* newLastNode = head;
    for(int i =0 ; i<lastNodePos;i++){
        newLastNode = newLastNode->next;

    }
    Node* newHead = newLastNode->next;
    newLastNode->next = nullptr;

   //find the end of list to join the new head
   Node* it = newHead;
   while(it->next !=nullptr){
    it = it->next;
   }
   it->next = head;
   return newHead;
}

int main(){
    Node* head = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(7);
    Node* fourth = new Node(8);
    Node* fifth = new Node(9);
    // Node* sixth = new Node(4);
    // Node* seventh = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next =  NULL;
    

    print(head);
    cout<<endl;
    head=rotateList(head , 3);
    cout<<endl;
    print(head);
}