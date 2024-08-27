#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int>&arr){
    int low = 0;
    int high = arr.size()-1;
   

    while(low<=high){
        int mid = low + (high - low) / 2;

        // Check if mid is the pivot
        if (mid < high && arr[mid] > arr[mid + 1]) {
            return arr[mid + 1];
        }
        // Check if mid-1 is the pivot
        else if (mid > low && arr[mid - 1] > arr[mid]) {
            return arr[mid];
        }
        // Decide which half to search in
        else if (arr[low] > arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return arr[0];
}

int main(){
    vector<int>arr{4,5,6,7,0,1,2};
    int ans = findPivot(arr);

    if(ans==-1){
        cout<<"Something wrong"<<endl;
    }
    else{
        cout<<"Minimum element is : "<<ans<<endl;
      
    }
}