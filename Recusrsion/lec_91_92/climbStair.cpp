#include<iostream>
using namespace std;

int climbStair(int n){
    if(n==0 || n==1){
        return 1;
    }
    return climbStair(n-1)+climbStair(n-2);
}

int main(){
    int n ;
    cout<<"Enter the number of stairs: ";
    cin>>n;
    
    int ans = climbStair(n);
    cout<<"The number of ways are: "<<ans;
}