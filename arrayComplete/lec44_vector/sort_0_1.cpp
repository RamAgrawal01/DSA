#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n ;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter 0 and 1 in the array: ";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int start =0;
    int end = n-1;
    int i=0;
    while(i != end){
         if(arr[i]==0){
            swap(arr[i],arr[start]);
            i++;
            start++;
        }
        else{
            swap(arr[i],arr[end]);
            //i++ not because new number will also check
            end--;
        }
    }
       
    
    cout<<"Your sorted array is: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}