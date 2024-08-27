#include<iostream>
using namespace std;

void transpose(int arr[][3],int rows , int cols , int trans[][3]){
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<cols ; j++){
            trans[j][i] = arr[i][j];
        }
    }
}

void printArray(int arr[][3],int rows , int cols){
    for(int i=0 ;i<rows ;i++){
        for(int j=0 ;j<cols ; j++){
            cout<<arr[i][j]<<" ";
        }
         cout<<endl;

    }
}

int main(){
     int arr[3][3];
    int rows = 3;
    int cols = 3;
    
    cout<<"ENter elements for 3 row and 3 col"<<endl;
    for(int i=0 ;i<3 ;i++){
        for(int j=0 ;j<3 ; j++){
            cin>>arr[i][j];
        }

    }

    cout<<"your array is: "<<endl;
    printArray(arr,rows,cols);
    int trans[3][3];
    transpose(arr,rows,cols,trans);
    cout<<"Transported Array: "<<endl;
    printArray(trans,rows,cols);
    
}

