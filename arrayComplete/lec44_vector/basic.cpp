#include<iostream>
#include<vector>
using namespace std;


int main(){
    //create vector
    vector<int>arr;
    cout<<arr.size()<<endl; //intital size 0
    cout<<arr.capacity()<<endl; //maximum elements can store

    //insert
    arr.push_back(5);
    arr.push_back(6);

       arr.pop_back();
    //   cout<<arr.capacity();

    
    for(int i=0 ; i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    int n;
    cout<<"Enter the number of element in array: ";
    cin>>n;
    vector<int>brr(n,10);
    cout<<"size of brr: "<<brr.size()<<endl;
    cout<<"capacity of brr: "<<brr.capacity()<<endl;

    for(int i=0 ; i<brr.size();i++){
        cout<<brr[i]<<" ";
    }
   

 

}