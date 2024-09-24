#include<iostream>
using namespace std;

void mergeTwoArr(int *arr , int s , int e){

    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int* left = new int[len1];
    int* right = new int[len2];

    //copy value
    int k = s;
    for(int i=0;i<len1;i++){
        left[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int i=0;i<len2;i++){
        right[i] = arr[k];
        k++;
    }


    //merginf
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex < len1 && rightIndex <len2){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex++] = left[leftIndex++];
            
        }
        else{
            arr[mainArrayIndex++] = right[rightIndex++];
            
        }
     
    }
    while(leftIndex<len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }
    while(rightIndex<len2){
        arr[mainArrayIndex++] = right[rightIndex++];
    }


}

void mergeSort(int*arr , int s , int e){

    //base case
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    //left part sort kar do 
    mergeSort(arr,s,mid);
    //right part sort kar do 
    mergeSort(arr,mid+1,e);

    //noew merging two sorted array
    mergeTwoArr(arr,s,e);
}

int main(){
    int arr[] = {4,5,13,2,12};
    int n = 5;
    int s = 0;
    int e = n-1;
    mergeSort(arr,s,e);

    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}