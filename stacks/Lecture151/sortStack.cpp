#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int>& st, int target) {
    // base case
    if(st.empty() || st.top() >= target) {
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();

    // recursive call
    insertSorted(st, target);

    // back topElement in stack
    st.push(topElement);
}

void sortStack(stack<int>& st) {
    // base case
    if(st.empty()) {
        return;
    }

    int temp = st.top();
    st.pop();

    // recursive call
    sortStack(st);

    // insert element in sorted order
    insertSorted(st, temp);
}

int main() {
    stack<int> st;

    st.push(33);
    st.push(22);
    st.push(87);
    st.push(12);
    st.push(76);

    cout << "Stack before sorting: ";
    stack<int> tempStack = st; // Create a copy of the stack to print its elements
    while(!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    sortStack(st);

    cout << "Stack after sorting: ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}