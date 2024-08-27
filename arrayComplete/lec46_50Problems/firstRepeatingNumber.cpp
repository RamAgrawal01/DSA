#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

firstRepeatingElement(vector<int> & arr){
     unordered_map<int, int> hash;
    for(int i=0;i<arr.size();i++){
        hash[arr[i]]++;
    }

    for(int i=0; i<arr.size() ; i++){
        if(hash[arr[i]] > 1){
            return i+1;
        }
    }
    return -1;
}


int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);

    cout<<"Enter the elements in the array: ";
    for(int i=0 ; i<n;i++){
        cin>>arr[i];
    }

    int repeatingElementIndex = firstRepeatingElement(arr);
    
    if(repeatingElementIndex != -1){
        cout<<"First repeating element is  at position: "<<repeatingElementIndex;
    }
    else{
        cout<<"No element repeated";
    }
}