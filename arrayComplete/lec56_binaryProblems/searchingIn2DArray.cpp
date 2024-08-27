#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<vector<int>>& matrix  , int target , int cols , int rows){
    int low = 0;
    int high = rows*cols-1;
    bool ans = false;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        int rowIndex = mid/cols;
        int colIndex = mid%cols;
        int element = matrix[rowIndex][colIndex];
        
        if(element == target){
            ans = true;
            return ans;
        }
        else if(element>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;

}

int main(){
  int r,c,target;
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

    cout<<"Enter the target value: ";
    cin>>target;

    bool ans = binarySearch(arr,target , c , r);

    if(ans==true){
        cout<<target<<" is Found"<<endl;
    }
    else{
        cout<<target<<" is Not Found";
    }


}