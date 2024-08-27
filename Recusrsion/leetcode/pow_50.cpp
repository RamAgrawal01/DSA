#include<iostream>
using namespace std;

double findPow(double num , int n){

      if (n < 0) {
        num = 1.0 / num;
        n = -n;
    }

    if(n==0){
        return 1;
    }
    return num*findPow(num , n-1);
}

int main(){
    int n ;
    double num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"Enter the power: ";
    cin>>n;

    double ans = findPow(num , n);
    cout<<"Answer is : "<<ans;
}