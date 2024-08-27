#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& arr , int target){
    vector<int> ans(2, -1); 
    int low = 0;
    int high= arr.size()-1;
    int mid = low + (high-low)/2;
    int firstIndex = -1;
    int lastIndex = -1;

   

    while(low<=high){
        if(arr[mid]==target){
            firstIndex = mid;
            high = mid-1;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
         mid = low + (high-low)/2;
        
    }

    //last occurence check , reset all variables
     low = 0;
     high= arr.size()-1;
     mid = low + (high-low)/2;

    while(low<=high){
        if(arr[mid]==target){
            lastIndex = mid;
            low = mid+1;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
         mid = low + (high-low)/2;
    }

     ans[0] = firstIndex;
     ans[1] = lastIndex;

    return ans;



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

     vector<int> result = searchRange(arr, target);

    cout << "Range of first and last occurrence is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}