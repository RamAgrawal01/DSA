#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void solve(vector<int>&arr,int sum , int& maxi , int i){
    if(i>=arr.size()){
        maxi =  max(sum , maxi);
        return ;
    }
     //exclude
     solve(arr,sum,maxi,i+1);
    //include
      solve(arr,sum+arr[i],maxi,i+2);
}

int main(){
    vector<int> arr{1,2,5};
    int sum =0;
    int maxi = INT_MIN;
    solve(arr,sum , maxi ,0);
     cout<<"Answer is: "<<maxi;
    return 0;
   
}