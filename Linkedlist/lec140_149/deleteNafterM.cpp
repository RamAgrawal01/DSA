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

Node* deleteNafterM(Node* head, int m, int n) {
    
    Node* current = head;

    // Traverse the linked list
    while (current != nullptr) {
        // Move `m` nodes ahead
        for (int i = 1; i < m && current != nullptr; ++i) {
            current = current->next;
        }

        // If we reached the end of the list
        if (current == nullptr) {
            break;
        }

        // Start from the next node to delete `n` nodes
        Node* temp = current->next;
        for (int i = 0; i < n && temp != nullptr; ++i) {
            Node* nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete;
        }

        // Connect the `current` node to the `temp` node after deleting `n` nodes
        current->next = temp;

        // Move `current` to the next node for the next iteration
        current = temp;
    }

    return head;
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
    head=deleteNafterM(head , 2,1);
    cout<<endl;
    print(head);
}