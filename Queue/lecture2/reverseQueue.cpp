#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){

    stack<int>s;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }

}


int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQueue(q);

    cout<<"Printing queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
