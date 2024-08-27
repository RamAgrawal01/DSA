#include<iostream>
#include<vector>
using namespace std;

void printSpiralForm(vector<vector<int>>& arr){
    int top =0 ;
    int bottom = arr.size()-1;
    int left = 0;
    int right = arr[0].size()-1;

    while(top<=bottom && left<=right){
        for(int i = left ; i<=right ; i++){
            cout<<arr[top][i]<<" ";
        }
        top++;


        for(int i=top ; i<=bottom ; i++){
            cout<<arr[i][right]<<" ";           
        }
        right--;

        if(top<=bottom){
            for(int i =right ; i>=left ;i--){
            cout<<arr[bottom][i]<<" ";           
        }
        bottom--;
        }
        

       if(left<=right){
         for(int i=bottom ; i>=top ;i--){
            cout<<arr[i][left]<<" ";           
        }
        left++;
       }
    }
}

int main(){
     int r,c;
    cout<<"Enter the number of rows: ";
    cin>>r;
    cout<<"Enter the number of coloumns: "; //intitally i use single literal which is only use for characterts
    cin>>c;

    vector<vector<int> > arr(r,vector<int>(c));

    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Printing array is : "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0 ; j<c ; j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

     cout << "Printing elements in spiral order: " << endl;
     printSpiralForm(arr);
     cout<<endl;
}