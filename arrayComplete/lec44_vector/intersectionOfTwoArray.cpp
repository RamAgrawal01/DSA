#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m , n;
    
     

    cout<<"Enter the number of element in Array 1: ";
    cin>>m;
     vector<int>arr(m);

    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }

    cout<<"Enter the number of element in Array 2: ";
    cin>>n;
    vector<int>brr(n);

    for(int i=0;i<brr.size();i++){
        cin>>brr[i];
    }

    vector<int>ans;
    //outer loop on arr vector
    for(int i=0 ; i<arr.size();i++){
        int element = arr[i];
        //for every element run loop on brr
        for(int j=0 ; j<brr.size();j++){
            if(element == brr[j]){
                ans.push_back(element);
                break;
            }
        }
    }
    cout<<"Intersection of two array is: ";
    for(int i=0 ; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

   

}