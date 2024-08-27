#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int>&arr , int target){
    int low = 0;
    int high = arr.size()-1;
    int mid = (low+high)/2;
    int index = -1;

    while(low<=high){
        if(arr[mid]==target){
            index = mid;
            high = mid-1;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else{
            high = high-1;
        }
        mid = (low+high)/2;
    }
    return index;
}

int main(){
    int n,target;
     cout<<"Enter the number of elements in array: ";
     cin>>n;

     vector<int> arr(n);
     cout<<"Enter the elements in increasing order: "<<endl;
     for(int i=0 ; i<arr.size();i++){
        cin>>arr[i];
     }

     cout<<"Enter the target value for searching: ";
     cin>>target;

     int targetIndex = firstOccurence(arr , target);

     if(targetIndex== -1){
        cout<<"Element not found";
     }
     else{
        cout<<target<<" first occurence at "<<targetIndex;
     }

    return 0;
}