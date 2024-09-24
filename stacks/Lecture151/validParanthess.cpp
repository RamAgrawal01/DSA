#include<iostream>
#include<stack>
using namespace std;

bool validParanthesis(string str){

    stack<char> st;

    for(int i =0 ; i<str.length() ; i++){

        char ch = str[i];

        //opening bracket
        if(ch=='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }
        //closing bracket
        else{
            
            if(!st.empty()){
                char topCh = st.top();
                if(ch==')' && topCh=='('){
                    st.pop();
                }

                else if(ch==']' && topCh=='['){
                    st.pop();
                }

                else if(ch=='}' && topCh=='{'){
                    st.pop();
                }

                else{
                    return false;
                }
            }    
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    
    string str = "{([])}";  

    bool isValid = validParanthesis(str);

    if (isValid) {
        cout << "Valid" << endl;
    } else {
        cout << "Not valid" << endl;
    }
}