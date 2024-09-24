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

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* temp  = curr->next;

    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* solve(Node* &head1 , Node* &head2){

    //1: reverse both linked list
    head1 = reverse(head1);
    head2 = reverse(head2);

    //2: add both linked list
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while(head1 !=NULL && head2!=NULL){

        int sum = carry+ head1->data + head2->data;
        int digit = sum%10;
        carry = sum/10;
        //create newNode
        Node* newNode = new Node(digit);

        if(ansHead == NULL){
            //insert first node
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail=newNode;
        }
        head1 = head1->next;
        head2=  head2->next;
    }
    //when head1 list is more than head 2
    while(head1!=NULL){
        int sum = carry +head1->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        head1=head1->next;
    }
    //when head2 list is more than head 1
        while(head2!=NULL){
        int sum = carry +head2->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        head2=head2->next;
    }
    //handle carry
    while(carry!=0){
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        head2=head2->next;

    }
    //step 3 : reverse the answer linked list
    ansHead = reverse(ansHead);
    return ansHead;
    
    
}

int main(){
    Node* head1 = new Node(2);
    Node* second1 = new Node(4);
    head1->next = second1;
    second1->next = NULL;

    Node* head2 = new Node(2);
    Node* second2 = new Node(3);
    Node* third2 = new Node(4);
    head2->next = second2;
    second2->next=third2;


    cout<<"Ist LL: ";
    print(head1);
    cout<<endl;
    cout<<"2nd LL; ";
    print(head2);
    cout<<endl;
    Node* ans=solve(head1,head2);
    print(ans);

   
}