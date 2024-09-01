#include<iostream>
#include<vector>
using namespace std;


void printSubArray_util(vector<int>&arr , int start , int end){
    //base case
    if(end == arr.size()){
        return;
    }
    //ist case
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //recursion
    printSubArray_util(arr,start,end+1);


}
void printSubArray(vector<int>&arr ){
    for(int start=0;start<arr.size();start++){
        int end = start;
        printSubArray_util(arr,start,end);
    }
}

int main(){
    vector<int>nums{1,2,3};
    printSubArray(nums);
    return 0;
}