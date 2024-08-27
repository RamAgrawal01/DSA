#include<iostream>
#include<vector>
#include <numeric>
#include<algorithm>
using namespace std;

bool isPackageShift(vector<int>& weights , int mid , int days) {
    
    int weightSum = 0;
    int count = 1;
    
    for(int i = 0 ; i<weights.size();i++){
        if(weights[i]>mid){
            return false;
        }

        if(weightSum+weights[i]>mid){
            count++;
            weightSum = weights[i];

            if(count>days){
                return false;
            }
        }
        else{
            weightSum = weightSum + weights[i];
        }
    }
    return true;
}

int shipWithinDays(vector<int>& weights, int days){
    int n = weights.size();
    int low = *max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(),weights.end(),0);
    int ans ;
    while(low<=high){
        int mid = low+(high-low)/2;

        if(isPackageShift(weights , mid , days)){
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
    vector<int>arr{1,2,3,1,1};
    int m = 4;
    int ans = shipWithinDays(arr,m);
    cout<<"Minimum capacity is: "<<ans;
}