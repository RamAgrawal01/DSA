#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int>arr) {
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl; 
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the elements in the array: ";


    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
     bool pairFound = false;

    cout<<"Your printed array is: ";
    printArray(arr);

      int sum;
    cout<<"Enter the value of key: ";
    cin>>sum;

    //printing all the pairs
    for(int i=0 ; i<arr.size();i++){
        int element = arr[i];

        //for every element wil traverse on ahead element
        for(int j=i+1 ; j<arr.size();j++){
            // cout<<"("<<element<<","<<arr[j]<<")"<<endl;

            if(element + arr[j]==sum){
                cout<<"Pair found: "<<element<<" "<<arr[j]<<endl;
                pairFound = true;
            }
                       
        }
        
    }
      if(!pairFound) {
        cout << "No pair found" << endl;
    }
}