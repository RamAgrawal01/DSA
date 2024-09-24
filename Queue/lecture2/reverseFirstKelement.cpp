#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseKDigitQueue(queue<int> &q , int k){

    stack<int>s;
    int count =0;

    if(k==0 && k>q.size()) return;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count==k){
            break;
        }
    }

    //vapas dalo
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    //push n-k element from q front to rear
    count =0;
    while(!q.empty() && (q.size()-k) != 0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count==q.size()-k){
            break;
        }
    }


}


int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);

    reverseKDigitQueue(q,3);

    cout<<"Printing queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}