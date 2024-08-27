#include <iostream>
using namespace std;

int main(){

    int arr[7];
    int size = 7;
    cout<<"Enter the 8 values in array: ";
    for(int i=0 ; i<7; i++){
        cin>>arr[i];
    }
   
    cout<<"Your array is : ";
    for(int i=0 ;i<7;i++){
        cout<<arr[i];
        cout<<" ";
    }
    cout<<endl;
    cout<<"Your array extermies are: ";

    int start =0 ;
    int end = size-1;

    while(true){
        if(start>end){
            break;
        }
        if(start==end){
            cout<<arr[start]<<" ";
        }
        else{
            cout<<arr[start]<<" ";
            cout<<arr[end]<<" ";
        }
        start++;
        end--;
    }

}