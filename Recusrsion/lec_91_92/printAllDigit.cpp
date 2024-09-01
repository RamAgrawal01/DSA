#include<iostream>
using namespace std;

void printDigits(int n){
    //base case
    if(n==0){
        return;
    }
    //recursion
    printDigits(n/10);
    //1 case
    int digit = n%10;
    cout<<digit<<" ";
    

}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    printDigits(n);
    return 0;
}