#include<iostream>
#include<limits.h>
using namespace std;

int findMax(int arr[] , int n , int i , int & maxi){
    //base case
    if(i>=n){
        return  ;
    }
    if(arr[i]>maxi){
        maxi=arr[i];
    }
    findMax(arr,n,i+1,maxi);
}


int main(){
    int maxi = INT_MIN;
    int arr[] ={10,20,30,60,50};
    int n = 5;
  
    findMax(arr,n , 0 , maxi);
    cout<<"MAximum number is : "<<maxi;
    return 0;
}