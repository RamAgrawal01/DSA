#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* mergeTwoSorted(Node* &p1 , Node* &p2){

    if(p1==NULL) return p2;
    if(p2==NULL) return p1;

    Node* ans = new Node(-1);
    Node* temp = ans;

     while (p1 != nullptr && p2 != nullptr) {
        if (p1->data <= p2->data) {
            temp->next = p1;
            p1 = p1->next;
        } else {
            temp->next = p2;
            p2 = p2->next;
        }
        temp = temp->next;
    }

    if (p1 != nullptr) {
        temp->next = p1;
    } else if (p2 != nullptr) {
        temp->next = p2;
    }
    return ans->next;
}

int main() {
    // Create first linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(5);
    // head1->next->next->next = new Node(4);
    // head1->next->next->next->next = new Node(5);

    // Create second linked list: 6 -> 3 -> 7 -> 5
    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(5);
    // head2->next->next->next = new Node(5);

    // Find and print intersection
    Node* intersection = mergeTwoSorted(head1, head2);

    cout << "After merging: ";
    printList(intersection);

    // Free memory (Note: In real applications, use proper memory management)
    delete head2->next->next->next; // Node with value 5
    delete head2->next->next; // Node with value 7
    delete head2->next; // Node with value 3
    delete head2; // Node with value 6
    delete head1->next->next->next->next; // Node with value 5
    delete head1->next->next->next; // Node with value 4
    delete head1->next->next; // Node with value 3
    delete head1->next; // Node with value 2
    delete head1; // Node with value 1

    return 0;
}