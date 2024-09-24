#include<iostream>
#include<deque>
using namespace std;

void firstNegativeKWindow(int arr[],int size , int k){

    //deque create
    deque<int>q;

    //process first window of size k
    for(int i=0 ; i<k ;i++){       
        if(arr[i]<0){
            q.push_back(i);
        }
    }
    //process remaining window ko process kro
    for(int i=k ; i<size ; i++){
        //answer de do purani window ka jo q ke front me hoga
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";
        }

        //out of window element ko remove karna ha
        while((i-q.front()>=k) && !q.empty()){
            q.pop_front();
        }
        //check current element for insertion
        if(arr[i]<0){
            q.push_back(i);
        }

      

    }
      //ans print kro last window ka
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";
        }
}

int main(){
    
    int arr[] ={12,-1,-7,8,-15,30,16,20};
    
    firstNegativeKWindow(arr,8,3);

    // cout<<"Printing queue: "<<endl;
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
}



