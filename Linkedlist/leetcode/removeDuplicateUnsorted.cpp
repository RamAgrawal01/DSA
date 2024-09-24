#include<iostream>
#include <unordered_set>
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

Node* deleteDuplicated(Node* head){
    unordered_set<int> countMap;
    if(head==NULL){
        return NULL;
    }
    //count occurence of each value
    Node* curr = head;
    Node* prev = NULL;

    while(curr!=NULL){
        //if current calue is duplicate
        if(countMap.find(curr->data) != countMap.end()){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            countMap.insert(curr->data);
            prev = curr;
            curr= curr->next;
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
    Node* output=deleteDuplicated(head);
    print(output);
}