#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseIterative(Node* head) {
    Node* temp = NULL;
    Node* current = head;

    // Swap next and prev for all nodes of the doubly linked list
    while(current != NULL) {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;
       current = current->prev;
    }

    // Before changing the head, check for the cases like empty
    // list and list with only one node
    if(temp != NULL) {
        head = temp->prev;
    }
    
    return head;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original Linked list: ";
    print(head);

    head = reverseIterative(head);

    cout << "Reversed Linked list: ";
    print(head);

    return 0;
}