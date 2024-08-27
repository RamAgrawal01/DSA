#include<iostream>
using namespace std;

int findQuotient(int dividend , int divisor){

    bool negativeResult = (dividend < 0) ^ (divisor < 0); // XOR to determine if signs are different

      dividend = abs(dividend);
      divisor = abs(divisor);
    
      int low =0;
      int high = dividend; //range of quotient is [0,dividend];
      int ans ;
       while(low<=high){
        int mid = low + (high-low)/2;

        if(mid*divisor<=dividend){
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return negativeResult ? -ans : ans;
}

int main(){
    int p , q;
    cout<<"Enter the value of dividend: ";
    cin>>q;
    cout<<"Enter the value of divisor: ";
    cin>>p;

    int quotient = findQuotient(q,p);
    cout<<"Quotient is : "<<quotient;

    return 0;

}