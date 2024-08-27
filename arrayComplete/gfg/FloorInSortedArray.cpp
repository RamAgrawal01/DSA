#include<iostream>
#include<vector>
using namespace std;

int findFloor(vector<int>arr , int x){
    int low = 0;
    int high = arr.size()-1;
    int ans = -1;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(arr[mid]>x){
            high = mid-1;
        }
        else{
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr{1,2,8,10,11,12,19};
    int target = 8;
    int result = findFloor(arr , target);
    cout<<"Result is: "<<result;
}