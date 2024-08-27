#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int>&arr){
    int low = 0;
    int high = arr.size()-1;
    
    while(low<=high){

        int mid = low + (high-low)/2;

        if(low == high){
            return low;
        }

        if(mid<high && arr[mid]>arr[mid+1] ){
            return mid;
        }
        else if(mid>low && arr[mid-1]>arr[mid]){
            return mid-1;
        }
        else if(arr[low]>arr[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
    return -1;
}

int main(){
    vector<int>arr{9,10,2,4,6,8};
    int ans = findPivot(arr);

    if(ans==-1){
        cout<<"Something wrong"<<endl;
    }
    else{
        cout<<"Pivot is placed at : "<<ans<<endl;
        cout<<"value of pivot is : "<<arr[ans];
    }
}