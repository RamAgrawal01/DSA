#include<iostream>
#include<vector>
#include <numeric>
using namespace std;

bool isPossibleSolution(int arr[] , int n , int k , int mid){
      int lengthSum = 0;
      int count = 1;
      
      for(int i=0;i<n;i++){
          if(arr[i]>mid){
              return false;
          }
          
          if(lengthSum+arr[i]>mid){
              count++;
              lengthSum = arr[i];
              
              if(count>k){
                  return false;
              }
          }
          else{
              lengthSum += arr[i];
          }
      }
      return true;
  }
  
    long long minTime(int arr[], int n, int k)
    {
       
       int low = 0 ;
       int high = accumulate(arr , arr+n , 0);
       int ans = -1;
       
       while(low<=high){
           int mid = low+(high-low)/2;
           
           if(isPossibleSolution(arr,n,k,mid)){
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
    int arr[] = {2,1};  // C-style array declaration
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    int m = 5;
    int ans = minTime(arr, n, m);
    cout << "Minimum pages is: " << ans;
    return 0;
}