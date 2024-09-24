#include<iostream>
#include<stack>
using  namespace std;

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

int main(){
    stack<int> st;
    int target = 11;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    // int n = st.size();
    insertAtBottom(st,target);
    cout << "Stack after inserting " << target << " at the bottom (from top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}