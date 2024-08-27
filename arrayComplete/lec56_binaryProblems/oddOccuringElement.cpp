#include<iostream>
#include<vector>
using namespace std;

int oddOccurence(vector<int>&arr){
    int low =0;
    int high = arr.size()-1;

    while(low<=high){

        if(low==high){
            return low;
        }
        int mid = low + (high-low)/2;

        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){ //it means arr[mid] is at even place and arr[mid+1]at odd
                low = mid+2;
            }
            else{
                high = mid; //because mid may be answer
            }

        }
        else{
            if(arr[mid-1]==arr[mid]){
                low = mid+1;
            }
            else{  //when we are on left side arr[mid-1]!= arr[mid];
                high = mid-1;
            }   
        }
    }
    return -1;
}

int main(){
    vector<int>arr{1,1,2,2,3,3,4,4,3,600,600,4,4};
    
    int index = oddOccurence(arr);
    cout<<"ELement which is odd occurence placed at: "<<index<<endl;
    cout<<"Element which is : "<<arr[index];
}