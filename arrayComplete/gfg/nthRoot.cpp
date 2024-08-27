#include<iostream>
#include<vector>
using namespace std;

long long intPower(int base, int exp, int m) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
        if (result > m)  // Early termination to prevent overflow
            return result;
    }
    return result;
}

int findRoot(int m , int n){
    int low = 0 ;
    int high = m;

   while (low <= high) {
        int mid = low + (high - low) / 2;
        long long power = intPower(mid, n ,m);  // Calculate mid^n
        
        if (power == m) {
            return mid;  // Found an integer root
        } else if (power > m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
    
}

int main(){
    int n , m;
    cout<<"Enter the value of nth for finding root: ";
    cin>>n;
    cout<<"Enter the digit: ";
    cin>>m;

    int ans = findRoot(m ,n);
    cout<<"Answer is : "<<ans;
}