#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isMakeBucket(vector<int>&bloomDay , int mid , int m , int k){
    int bucket = 0;
    int flowers = 0;
    
    for(int bloom : bloomDay){
        if(bloom<=mid){
            flowers++;
            if(flowers == k){
                bucket ++;
                flowers = 0;
            }
        }
        else{
            flowers = 0; 
        }
    }
    if(bucket==m){
        return true;
    }
    else{
        return false;
    }
}

int minDays(vector<int>&bloomDay , int m , int k){
    int n = bloomDay.size();
    long long totalFlowersNeed = (long long)m*k;
    if(n<totalFlowersNeed) {
        return -1;
    }

    int low = *min_element(bloomDay.begin() , bloomDay.end());
    int high = *max_element(bloomDay.begin() , bloomDay.end());
    int ans = -1;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(isMakeBucket(bloomDay , mid , m , k)){
            ans = mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> bloomDay = {1000000000,1000000000};
    int m = 1;
    int k = 1;
    cout << "Minimum number of days: " << minDays(bloomDay, m, k) << endl;
    return 0;
}