#include<iostream>
using namespace std;

int partition(int arr[],int low , int high){
    //choose pivot element
    int pivotIndex = low;
    // int pivotElement = arr[low];

    //find right position for pivot element
    int count =0;
    for(int i  = low+1 ;i<=high ; i++){

        if(arr[i]<= arr[pivotIndex]){
            count++;
        }
    }
    //jab loop se bahar aaya to pivot ki right positionka index ready h
    int correctIndex = low+count;
    swap(arr[pivotIndex],arr[correctIndex]);
    pivotIndex = correctIndex;

    //left me chote or right me bade
    int i = low;
    int j = high;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=arr[pivotIndex]){
            i++;
        }
        while(arr[j]>arr[pivotIndex]){
            j--;
        }

        //2 case ho skte h 
        //A-> found the element for swapping
        //B-> no need to swap
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;
}


void quickSort(int arr[],int low , int high){
    //base case
    if(low>=high){
        return;
    }

    //partition logic 
    int p = partition(arr,low,high);

    //recursive call
   
    //left
     quickSort(arr,low,p-1);
     //right
     quickSort(arr,p+1,high);


}

int main(){
    int arr[] = {8,1,3,20,50,30};
    int n =7;
    int low =0;
    int high = n-1;
    quickSort(arr,low,high);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}