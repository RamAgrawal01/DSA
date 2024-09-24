#include<iostream>
#include<stack>
using namespace std;



void insertAtBottom(stack<int>&st , int target){

    //basr cse
    if(st.empty()){
        st.push(target);
        return;
    }
    //store the inforamtion and delete it
    int temp = st.top();
    st.pop();

    //recursive call
    insertAtBottom(st,target);

    //push all temp values
    st.push(temp);
}

void reverseStack(stack<int>&st){

    //base case
    if(st.empty()){
        return;
    }

    int target = st.top();
    st.pop();

    //reverse
    reverseStack(st);

    //insertAtBottom
    insertAtBottom(st,target);
}

int main(){
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    int n = st.size();
    reverseStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}