#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleave(queue<int>&q){

    queue<int> newQ;
    int halfSize = q.size() / 2;
    int count = 0;

    // Move the first half of the elements to newQ
    while (count < halfSize) {
        int temp = q.front();
        q.pop();
        newQ.push(temp);
        count++;
    }

    //   cout<<"Printing new queue: "<<endl;
    // while(!newQ.empty()){
    //     cout<<newQ.front()<<" ";
    //     newQ.pop();
    // }
    // cout<<endl;


    while (!newQ.empty()) {
        q.push(newQ.front());
        newQ.pop();
        q.push(q.front());
        q.pop();
    }

    
}


int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    interleave(q);

    cout<<"Printing queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}