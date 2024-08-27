#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    //sorting method
    // int n;
    // cout<<"Enter the number of elements in Array: ";
    // cin>>n;

    // vector<int> arr(n);
    // cout<<"Enter the elements 0,1 and 2 in the array: ";
    // for(int i=0 ; i<n;i++){
    //     cin>>arr[i];
    // }
    // sort(arr.begin(),arr.end());
    
    // for(int i=0 ;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    //******COUNTING METHOD**************** */
    
    // int n;
    // cout<<"Enter the number of elements in Array: ";
    // cin>>n;

    // vector<int> arr(n);
    // cout<<"Enter the elements 0,1 and 2 in the array: ";
    // for(int i=0 ; i<n;i++){
    //     cin>>arr[i];
    // }

    // int zeroes , ones , twos;
    // zeroes = ones = twos = 0;
    // for(int i=0 ; i<arr.size();i++){
    //     if(arr[i]==0){
    //         zeroes++;
    //     }
    //     else if(arr[i]==1){
    //         ones++;
    //     }
    //     else{
    //         twos++;
    //     }
    // }
    // //spread 
    // int i =0;
    // while(zeroes--){
    //     arr[i]=0;
    //     i++;
    // }
    // while(ones--){
    //     arr[i]=1;
    //     i++;
    // }
    //  while(twos--){
    //     arr[i]=2;
    //     i++;
    // }

    //   for(int i=0 ;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    //Three pointer approach

     int n;
    cout<<"Enter the number of elements in Array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements 0,1 and 2 in the array: ";
    for(int i=0 ; i<n;i++){
        cin>>arr[i];
    }

    int start = 0;
    int end = n-1;
    int i =0;
    while(i <= end){
        if(arr[i]==0){
            swap(arr[i],arr[start]);
            i++;
            start++;
        }
        else if(arr[i]==1){
            i++;
        }
        else{
            swap(arr[i],arr[end]);
            end--;
            }
        }
    
    cout<<"Sorted color array is: ";
        for(int i=0 ;i<n;i++){
        cout<<arr[i]<<" ";
    }



}