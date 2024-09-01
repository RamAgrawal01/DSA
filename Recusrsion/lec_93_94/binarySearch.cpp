#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>&arr ,int low , int high, int target){
    int mid = low +(high-low)/2;
    //base case
    if(low>high){
        return -1;
    }
    if(arr[mid]==target){
        return mid;
    }
    //case 1
    if(arr[mid]<target){
        return binarySearch(arr , mid+1 , high , target);
    }
    else{
        return  binarySearch(arr , low , mid-1 , target);
    }
}

int main(){
    vector<int> arr{12,23,33,56,58,78,87};
    int target = 87;
    int low = 0;
    int high = arr.size()-1;
    int ans = binarySearch(arr , low , high , target);
    cout<<target<<" is placed at : "<<ans;
}