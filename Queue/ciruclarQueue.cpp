#include <iostream>
using namespace std;

class CirQueue {
public:
    int size;
    int *arr;
    int front;
    int rear;

    CirQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int x) {
        // Queue full condition
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % size)) {
            cout << "Queue is full" << endl;
            return;
        }
        // Single element case (queue is empty)
        else if (front == -1) {
            front = rear = 0;
            arr[rear] = x;
        }
        // Circular nature
        else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = x;
        }
        // Normal flow
        else {
            rear++;
            arr[rear] = x;
        }
    }

    void pop() {
        // Empty check
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        // Single element case
        else if (front == rear) {
            front = rear = -1;
        }
        // Circular nature
        else if (front == size - 1) {
            front = 0;
        }
        // Normal flow
        else {
            front++;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CirQueue q(5);

    // Perform operations
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); // This should show "Queue is full"

    q.display();

    q.pop();
    q.pop();

    q.display();

    q.push(60);
    q.push(70); // This should wrap around and add elements

    q.display();

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.display(); // Should be empty now

    q.push(80);
    q.display();

    return 0;
}
