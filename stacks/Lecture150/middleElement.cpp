#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int> &st ,int &totalSize){

    //base case
    if(st.size() == totalSize/2 +1){
        cout<<"Middle element is: "<<st.top()<<endl;
    }

    int temp = st.top();
    st.pop();

    //recurive call
    printMiddle(st,totalSize);

    // Add the removed element back to the stack
    st.push(temp);
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
    printMiddle(st,n);
}