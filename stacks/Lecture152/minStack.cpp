#include<iostream>
#include<vector>
using namespace std;

class MinStack{
    public:
        vector<pair<int,int> >st;

        MinStack(){

        }

        void push(int val){

            if(st.empty()){
                pair<int,int>p=make_pair(val,val);
                st.push_back(p);
            }
            else{
                pair<int,int> p;
                p.first = val;
                p.second= min(val,st.back().second);
                st.push_back(p);
            }
        }

        void pop(){
            st.pop_back();
        }
        int top(){
           return st.back().first;
        }
        int getMin(){
            return st.back().second;
        }
};

int main() {
    MinStack minStack;

    minStack.push(5);
    cout << "Pushed 5, Min: " << minStack.getMin() << endl;

    minStack.push(3);
    cout << "Pushed 3, Min: " << minStack.getMin() << endl;

    minStack.push(7);
    cout << "Pushed 7, Min: " << minStack.getMin() << endl;

    minStack.push(1);
    cout << "Pushed 1, Min: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "Popped, Min: " << minStack.getMin() << endl;

    cout << "Top element: " << minStack.top() << endl;

    minStack.pop();
    cout << "Popped, Min: " << minStack.getMin() << endl;

    return 0;
}