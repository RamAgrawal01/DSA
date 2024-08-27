#include<iostream>
#include<vector>
using namespace std;

void printWaveColumnWiseForm(vector<vector<int>>& arr) {
    for(int col = 0; col < arr[0].size(); col++) {
        if(col % 2 == 0) {
            for(int row = 0; row < arr.size(); row++) {
                cout << arr[row][col] << " ";
            }
        } else {
            for(int row = arr.size() - 1; row >= 0; row--) {
                cout << arr[row][col] << " ";
            }
        }
    }
    // cout << endl;
}

void printRowWaveForm(vector<vector<int>>& arr) {
    for(int row = 0; row < arr.size(); row++) {
        if(row % 2 == 0) {
            for(int col = 0; col < arr[0].size(); col++) {
                cout << arr[row][col] << " ";
            }
        } else {
            for(int col = arr[0].size() - 1; col >= 0; col--) {
                cout << arr[row][col] << " ";
            }
        }
    }
    cout << endl;
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

     cout << "Printing array in column wave form: " << endl;
     printWaveColumnWiseForm(arr);
     cout<<endl;

        cout << "Printing array in row wave form: " << endl;
       printRowWaveForm(arr);

     return 0;
}