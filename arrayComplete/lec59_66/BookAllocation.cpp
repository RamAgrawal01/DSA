#include<iostream>
#include<vector>
#include <numeric>
using namespace std;

bool isPossibleSolution(vector<int>& arr, int n, int m, int mid) {
    int pageSum = 0;
    int count = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            return false;
        }

        if (pageSum + arr[i] > mid) {
            count++;
            pageSum = arr[i];

            if (count > m) {
                return false;
            }
        } else {
            pageSum += arr[i];
        }
    }
    return true;
}

int minimumPages(vector<int>&arr , int m){
    int n = arr.size();
    if(m>n){
        return -1;
    }

    int low = 0;
    int high = accumulate(arr.begin() , arr.end() , 0);
    int ans = -1;

    while(low<=high){
        int mid = low+(high-low)/2;

        if(isPossibleSolution(arr , n , m , mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr{10,20,30,40};
    int m = 2;
    int ans = minimumPages(arr,m);
    cout<<"Minimum pages is: "<<ans;
}