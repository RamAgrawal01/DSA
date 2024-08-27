#include<iostream>
using namespace std;


//we neeed t0 compulsory to tell number of cols here because of there fomeula c*i+j
void printRowWiseSum(int arr[][3] , int rows , int cols){
    //row wise traversal
    cout<<"Sum of all rows is given below: "<<endl;
    for(int i=0 ; i<rows ;i++){
        int sum =0;
        for(int j=0 ; j<cols ; j++){
            sum = sum+arr[i][j];
        }
        cout<<"Sum of row "<<i+1<<" is: "<<sum<<endl;
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
    for(int i=0 ;i<3 ;i++){
        for(int j=0 ;j<3 ; j++){
            cout<<arr[i][j]<<" ";
        }
         cout<<endl;

    }
    printRowWiseSum(arr , rows , cols);
   
}