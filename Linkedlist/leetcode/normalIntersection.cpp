#include <iostream>
#include <vector>
#include <algorithm> // Ensure this is included for std::find
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to find the intersection of two linked lists
Node* findIntersection(Node* head1, Node* head2) {
    vector<int> values;
    Node* current = head1;

    // Store values of the first list in a vector
    while (current != nullptr) {
        values.push_back(current->data);
        current = current->next;
    }

    // Create a new list to store the intersection
    Node* intersectionHead = nullptr;
    Node* intersectionTail = nullptr;

    current = head2;
    while (current != nullptr) {
        // Check if current node's data is in the vector
        if (find(values.begin(), values.end(), current->data) != values.end()) {
            // Create a new node for the intersection list
            Node* newNode = new Node(current->data);
            if (intersectionHead == nullptr) {
                intersectionHead = newNode;
                intersectionTail = newNode;
            } else {
                intersectionTail->next = newNode;
                intersectionTail = newNode;
            }
        }
        current = current->next;
    }

    return intersectionHead;
}

// Helper function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create first linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Create second linked list: 6 -> 3 -> 7 -> 5
    Node* head2 = new Node(6);
    head2->next = new Node(3);
    head2->next->next = new Node(7);
    head2->next->next->next = new Node(5);

    // Find and print intersection
    Node* intersection = findIntersection(head1, head2);

    cout << "Intersection: ";
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