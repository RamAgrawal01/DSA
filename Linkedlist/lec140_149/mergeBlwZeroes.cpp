#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* mergeBZeroes(Node* &head){

    Node*slow = head;
    Node*fast = head->next;
    Node* temp = new Node(-1);
    Node* tail = temp;

    while(fast!=nullptr){
        int sum = 0;

        while(fast->data != 0){
            sum = sum+fast->data;
            fast=fast->next;
        }
        //if sum output find then make a node
        if(sum!=0){
                Node* newNode = new Node(sum);
                tail->next = newNode;
                tail = newNode;
    }

    if(fast!=nullptr){
        slow = fast;
        fast=fast->next;
    }


}
    Node* result = temp->next;
    delete temp;
    return result;

}

int main(){
    Node* head = new Node(0);
    Node* second = new Node(3);
    Node* third = new Node(1);
    Node* fourth = new Node(0);
    Node* fifth = new Node(4);
    Node* sixth = new Node(5);
    Node* seventh = new Node(2);
    Node* eight = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = NULL;
    

    print(head);
    cout<<endl;
    head=mergeBZeroes(head);
    cout<<endl;
    print(head);
}