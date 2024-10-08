#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i , int j , int row , int col , int arr[3][3] , vector<vector<bool> >&visited){

    if (( (i>=0 && i<row) && (j>=0 && j<col)) &&
    (arr[i][j]==1) &&
    (visited[i][j]==false) ) {
        return true;
    }
    else{
        return false;
    }
}

void solveMaze(int arr[3][3],int row ,int col, int i,int j , 
vector<vector<bool> >&visited , vector<string>&path , string output){

    //base case
    if(i == row-1 && j == col-1){
        path.push_back(output);
        return;
    }

    //Down
    if(isSafe(i+1,j , row , col  ,arr,visited )){
        visited[i+1][j] = true;
        solveMaze(arr,row,col,i+1,j,visited,path,output+'D');
        //backtracl
        visited[i+1][j] = false;
    }

    //Left
        if(isSafe(i,j-1 , row , col  ,arr,visited )){
        visited[i][j-1] = true;
        solveMaze(arr,row,col,i,j-1,visited,path,output+'L');
        //backtracl
        visited[i][j-1] = false;
    }

    //Right
        if(isSafe(i,j+1 , row , col  ,arr,visited )){
        visited[i][j+1] = true;
        solveMaze(arr,row,col,i,j+1,visited,path,output+'R');
        //backtracl
        visited[i][j+1] = false;
    }

    //Up
        if(isSafe(i-1,j , row , col  ,arr,visited )){
        visited[i-1][j] = true;
        solveMaze(arr,row,col,i-1,j,visited,path,output+'U');
        //backtracl
        visited[i-1][j] = false;
    }
}

int main(){
    int maze[3][3] = { 
                    {1,0,0},
                     {1,1,0},
                    {1,1,1}
                             };
    int row = 3;
    int col = 3;

    vector<vector<bool> > visited(row,vector<bool>(col,false));
    visited[0][0] = true;
    vector<string> path;
    string output = "";
    solveMaze(maze,row,col,0,0,visited , path , output);

    cout<<"printing the result: "<<endl;
    
    for(auto i:path){
        cout<<i<<" ";
    }
    cout<<endl;
}
