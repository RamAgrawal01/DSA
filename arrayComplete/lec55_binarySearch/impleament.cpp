#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr , int target){
    int low = 0;
    int high = arr.size()-1;
    int mid = (low+high)/2;

    while(low<=high){
        if(arr[mid]== target){
            return mid;
        }
        else if(arr[mid]>target){
            high = mid-1;
        }
        else{
            low = low+1;
        }
        mid = (low+high)/2;
    }
    return -1;
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

     int targetIndex = binarySearch(arr , target);

     if(targetIndex== -1){
        cout<<"Element not found";
     }
     else{
        cout<<target<<" found at "<<targetIndex;
     }

    return 0;
     

}