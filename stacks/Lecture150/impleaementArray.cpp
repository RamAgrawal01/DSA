#include<iostream>
using namespace std;

class Stack{
    public:

    int* arr;
    int top;
    int size;

    Stack(int size){
        arr = new int(size);
        this->size = size;
        top= -1;
    }

    void push(int data){
        //if space is available
        if(size-top>1){
            top++;
            arr[top] = data;
        }
        //if not available
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"stack is underflow"<<endl;
        }
        else{
            top--;
        }
    }

    int getTop(){
        if(top==-1){
            cout<<"Stack is underflow"<<endl;
        }
        else{
            return arr[top];
        }
    }

    int getSize(){
        return top+1;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Stack st(10);

    //insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(50);
    //printing stack
    while(!st.isEmpty()){
        cout<<st.getTop()<<" ";
        st.pop();
    }

    //size
    cout<<"size: "<<st.getSize();


}