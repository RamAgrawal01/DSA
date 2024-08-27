#include<iostream>
#include<vector>
using namespace std;

//with no dupliactes

int main(){

    int arr[] ={1,3,5,7,9};
    int sizeA = 5;
    int brr[] ={2,4,6,8};
    int sizeB = 4;

    vector<int>ans;
    //push all elements of vector arr
    for(int i =0 ; i<sizeA ; i++){
        ans.push_back(arr[i]);
    }

      //push all elements of vector brr
    for(int i =0 ; i<sizeB ; i++){
        ans.push_back(brr[i]);
    }

    //printing
    cout<<"Printing unioun Array: ";
    for(int i=0 ;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}