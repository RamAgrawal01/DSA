#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

int maxProfitFinder(vector<int>&arr ,int index , int&minPrice , int& maxProfit ){
    //base case
    if(index>=arr.size()){
        return 0;
    }
    //case 1;
    minPrice = min(minPrice,arr[index]);
    int profit = arr[index]-minPrice;
    maxProfit = max(maxProfit,profit);

    //recursiom
    maxProfitFinder(arr,index+1,minPrice,maxProfit);
}

int findMaxProfit(vector<int>&arr ){
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(arr,0,minPrice,maxProfit);
    return maxProfit;
}

int main(){
    vector<int>arr{8,2,6,8,3,2,7,8,9,7,6,51,6,8,9};
    int ans = findMaxProfit(arr);
    cout<<ans;
}