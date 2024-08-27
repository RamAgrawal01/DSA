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

int binarySearch(vector<int>arr , int low , int high , int target){
   
      while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid]==target){
            return mid;
        }
        else if( arr[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

 int search(vector<int>& arr, int key) {
        int pivotIndex = findPivot(arr);
        cout<<"Checking pivot index: "<<pivotIndex<<endl;
        int ans = -1;
       if(key>=arr[0] && key <= arr[pivotIndex] ){
            ans = binarySearch(arr , 0 , pivotIndex , key);
           
       }
       else{
            ans = binarySearch(arr , pivotIndex+1, arr.size()-1 , key);
            
       }
       return ans;
    }

int main(){
    vector<int>arr{4,5,6,7,0,1,2};
    int target = 3;
    int ans = search(arr,target);

    
        cout<<"target is placed at : "<<ans<<endl;
        cout<<"value of target is : "<<arr[ans];
    
}
