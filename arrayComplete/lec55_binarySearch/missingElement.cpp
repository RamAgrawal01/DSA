#include<iostream>
#include<vector>
using namespace std;

int elementMissing(vector<int> &arr){
    int low = 0;
    int high = arr.size()-1;
    int mid = low + (high-low)/2;

    while(low<=high){
        if(arr[mid]==mid){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        mid = low +(high-low)/2;
    }
    return mid;
}


int main(){
    int n;
     cout<<"Enter the number of elements in array: ";
     cin>>n;

     vector<int> arr(n);
     cout<<"Enter the elements in increasing order: "<<endl;
     for(int i=0 ; i<arr.size();i++){
        cin>>arr[i];
     }

     int missingElement = elementMissing(arr);

        cout<<"Missing element is: "<<missingElement;
    

    return 0;
}