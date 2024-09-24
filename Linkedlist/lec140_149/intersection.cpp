#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    Node* ptrA = headA;
    Node* ptrB = headB;

    // Traverse both lists
    while (ptrA != ptrB) {
        // If ptrA reaches the end of its list, redirect it to headB
        ptrA = (ptrA == nullptr) ? headB : ptrA->next;
        // If ptrB reaches the end of its list, redirect it to headA
        ptrB = (ptrB == nullptr) ? headA : ptrB->next;
    }

    // Either both pointers meet at the intersection node, or both are null
    return ptrA;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list A: 1 -> 2 -> 3 -> 4 -> 5
    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = new Node(4);
    headA->next->next->next->next = new Node(5);

    // Create list B: 9 -> 8 -> 3 -> 4 -> 5 (intersect at node with value 3)
    Node* headB = new Node(9);
    headB->next = new Node(8);
    headB->next->next = headA->next->next; // Point to node with value 3

    // Print lists
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    // Find intersection
    Node* intersection = getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection" << endl;
    }

    // Free memory (Note: This is a simple example. In real applications, consider proper memory management.)
    delete headB->next->next->next->next; // Node with value 5
    delete headB->next->next->next; // Node with value 4
    delete headB->next->next; // Node with value 3 (shared part, do not delete in headA)
    delete headB->next; // Node with value 8
    delete headB; // Node with value 9
    delete headA->next->next; // Node with value 3 (part of shared segment)
    delete headA->next->next->next; // Node with value 4
    delete headA->next->next->next->next; // Node with value 5
    delete headA->next; // Node with value 2
    delete headA; // Node with value 1

    return 0;
}