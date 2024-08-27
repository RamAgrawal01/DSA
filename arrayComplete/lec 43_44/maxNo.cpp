#include <iostream>
#include <limits.h> // Note: <limits.h> is the C header, for C++ use <limits>

using namespace std;

int main() {

    int arr[5];
    cout<<"Enter the 5 values in array: ";
    for(int i=0 ; i<5; i++){
        cin>>arr[i];
    }
   
    cout<<"Your array is : ";
    for(int i=0 ;i<5;i++){
        cout<<arr[i];
        cout<<" ";
    }

    int maxi = INT_MIN; 
    int mini = INT_MAX;

    for(int i=0 ; i<5;i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
        if(arr[i]<mini){
            mini = arr[i];
        }
    }
    cout<<endl;
    cout<<"Maximum number in array is: "<<maxi<<endl;
    cout<<"Minimum number in array is: "<<mini;


    
}