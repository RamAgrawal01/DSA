#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;

    for(int row=0 ; row<n ;row++){
        for(int col=0 ; col<(n-row) ; col++){
            if(row==0 || col==0 || (row+col)==n-1){
                cout<<(row+col)+1;
            }
            else{
                cout<<" ";
            }
            cout<<" ";
            
        }
        cout<<endl;
    }
}