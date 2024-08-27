#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr{1,3,3,3,3};
    
    for(int i=0 ; i<arr.size();i++){
        int index = abs(arr[i]);
        if(arr[index-1]>0){
            arr[index-1] = -arr[index-1];
        }
    }
    cout<<"Missing numbers: ";
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
           cout<<i+1<<" ";
        }
    }
}