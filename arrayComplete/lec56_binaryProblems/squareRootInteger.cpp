#include<iostream>
#include<vector>
using namespace std;

int findSqrt(int n){
    int l = 0;
    int h = n;
    int ans = -1;

    while(l<=h){
        int mid = l + (h-l)/2;

        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid>n){
            h = mid-1;
        }
        else{
            ans = mid;
            l = mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number for square root: ";
    cin>>n;

    int ans = findSqrt(n);
    cout<<"Square root of "<<n<<" is: "<<ans<<endl;

    int precision;
    cout<<"Enter the number of floating digits in precision: ";
    cin>>precision;

    double step = 0.1;
    double finalAns = ans;

    for(int i =0 ; i<precision ; i++){
        for(double j=finalAns ; j*j<=n ; j = j+step){
            finalAns = j;
        }
        step = step/10;
    }
    cout<<"Accurate square root of number: "<<finalAns;
}