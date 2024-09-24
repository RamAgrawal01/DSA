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

Node* reverseLLAfterMiddle(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* temp = curr;

    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev= curr;
        curr= temp;
    }
   
    return prev;
}

bool checkPalindrome(Node* &head){

    if(head==NULL){
        return true;
    }
    if(head->next == NULL){
        return true;
    }

    //find the middle node
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL){
        fast= fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    cout<<"Middle is: "<<slow->data<<endl;;

    //reverse linked list adter middle(slow)
    Node* reverseLLKaHead = reverseLLAfterMiddle(slow->next);
    

    //attach half of reverse LL to the slow
    slow->next = reverseLLKaHead;

    //start comparison both hald
    Node* temp1 = head;
    Node* temp2 = reverseLLKaHead;

    while(temp2!=NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
    

}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(30);
    Node* fifth = new Node(20);
    Node* sixth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next =  sixth;
    sixth->next = NULL;

    print(head);
    cout<<endl;
    bool isPalindrome = checkPalindrome(head);

   cout<<isPalindrome;
}