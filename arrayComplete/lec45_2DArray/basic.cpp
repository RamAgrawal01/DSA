#include<iostream>
using namespace std;

int main(){
    //declare 2D array
    int arr[3][3];
    
    //initialization
    int brr[3][3]={{1,2,3} , {4,5,6} , {7,8,9}};
    //row wise printing
    cout<<"Row wise printing"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<brr[i][j]<<" ";
            
        }
        cout<<endl;
    }

    //col wise printing
    cout<<"Column wise printing"<<endl;
   for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<brr[j][i]<<" ";
            
        }
        cout<<endl;
    }

    int crr[4][3];
    int rows = 4;
    int cols = 3;

    cout<<"Enter the 2D Array for 4 row and 3 cols"<<endl;
    for(int i=0 ; i<rows ; i++){
        for(int j=0;j<cols;j++){
            cin>>crr[i][j];
        }
    }

    cout<<"Printing row wise"<<endl;
    for(int i=0 ; i<rows ; i++){
        for(int j=0;j<cols;j++){
            cout<<crr[i][j]<<"   ";
        }
        cout<<endl;
    }
    

}