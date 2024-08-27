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
    int n,sum ;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the elements:  ";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    cout<<"Your printed array is: ";
    printArray(arr);

    bool pairFound = false;

    cout<<"Enter the value of sum: ";
    cin>>sum;

    for(int i=0 ; i<n;i++){
        int firstElement = arr[i];

        for(int j=i+1 ; j<n ; j++){
            int secElement = arr[j];

            for(int k = j+1 ; k<n ; k++){
                if(firstElement + secElement + arr[k]==sum){
                    cout<<"Pair found: "<<"("<<firstElement<<","<<secElement<<","<<arr[k]<<")"<<endl;
                    pairFound = true;
                }
            }
        }
    }
   if(!pairFound) {
        cout << "No pair found" << endl;
    }

}