#include<iostream>
#include<stack>
using namespace std;

int longestValidBracket(string s){

    stack<int>st;
    st.push(-1);
     int maxLen=0;
    for(int i=0;i<s.length();i++){

        char ch = s[i];
       
        //if characher is opening bracket
        if(ch=='('){
            st.push(i);
        } 
        //if charachet is closing bracket
        else{
            st.pop();
            //if stack is empty
            if(st.empty()){
                st.push(i);
            }
            //if stack is not empty
            else{
                int len = i-st.top();
                maxLen=max(len,maxLen);
            }
        }
    }
    return maxLen;
}

int main(){
    string str = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
    int ans = longestValidBracket(str);
    cout<<ans;
}