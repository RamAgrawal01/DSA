#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int>&arr , int index){
    if(index>=arr.size()){
        return;
    }
    cout<<arr[index]<<" ";
    printArray(arr,index+1);
}

int main(){
    vector<int>arr(5);
    cout<<"Enter the elements: ";
    for(int i = 0 ; i<arr.size();i++){
        cin>>arr[i];
    }
    printArray(arr,0);
}