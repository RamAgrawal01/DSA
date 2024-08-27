#include<iostream>
#include<vector>
using namespace std;

int findPeakIndex(vector<int>arr){
    int low =0;
    int high = arr.size()-1;
    int mid = low + (high-low)/2;

    while(low<high){
        if(arr[mid]<arr[mid+1]){
            low = mid+1;
        }
        else{
            high = mid;
        }
        mid = low+(high-low)/2;
    }
    return low;
}

int main(){
    vector<int> arr{0,5,10,2};

    int peakElement= findPeakIndex(arr);
    cout<<"Peak element is at : "<<peakElement;
}