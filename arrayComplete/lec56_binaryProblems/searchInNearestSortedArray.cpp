//nearest sorted array is : index in sorted array may be present in i , i-1 and i+1;

#include<iostream>
#include<vector>
using namespace std;

int searchInNearlySorted(vector<int>arr , int target){
    int low = 0;
    int high = arr.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]==target){
            return mid;
        }
        if (mid > low && arr[mid - 1] == target) {  // Check if mid-1 is within bounds
            return mid - 1;
        }
        if (mid < high && arr[mid + 1] == target) {  // Check if mid+1 is within bounds
            return mid + 1;
        }
        else if(arr[mid]>target){
            high = mid-2;
        }
        else{
            low = mid+2;
        }
    }
}

int main(){
    vector<int>arr{10,3,40,20,50,80,70};
    int target = 70;

    int ans = searchInNearlySorted(arr,target);
    cout<<"Target "<<target<<" is placed at: "<<ans;
    
}