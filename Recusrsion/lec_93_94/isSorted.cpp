#include<iostream>
#include<vector>
using namespace std;

bool isArraySorted(vector<int>&arr , int i ){
    if(i==arr.size()-1){
        return true;
    }
    if(arr[i+1]<arr[i]){
        return false;
    }
    return isArraySorted(arr,i+1);

}

int main(){
    vector<int> arr{10,20,30,25,65,76};
    bool ans = isArraySorted(arr,0);
    if(ans){
        cout<<"Array is sorted";
    }
    else{
        cout<<"Array is not sorted";
    }
    return 0;
}

