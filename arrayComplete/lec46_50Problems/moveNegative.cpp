#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Assume no order maintain
//time complexity o(n);
//space complexity o(1);

int main(){
    int n;
    cout<<"Enter the number of elements in Array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements 0,1 and 2 in the array: ";
    for(int i=0 ; i<n;i++){
        cin>>arr[i];
    }

    int low =0;
    int high = arr.size()-1;
    while(low<=high){
        if(arr[low]<0){
            low++;
        }
        else if(arr[high]>0){
            high--;
        }
        else{
            swap(arr[low],arr[high]);
        }
    }
      cout<<"Array after negative integer moving: ";
        for(int i=0 ;i<n;i++){
        cout<<arr[i]<<" ";
    }
}