#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<char>> & board ,int n){

    for(int i = 0 ; i<n ; i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}

bool isSafe(int row , int col , vector<vector<char>>&board,int n){
    //check current cell is feasible for current queen
    int i = row;
    int j = col;

    //cjecking left column 
    while(j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        j--;
    }

    //check upper left diagonal
     i =row;
    j = col;

    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    
    //check bottom left diagonal
     i = row;
     j = col;

    while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }

    //kahi bhi queen nhi mili matlab safe
    return true;

}

void solve(vector<vector<char>> & board , int col , int n){

    //base case
    if(col>=n){
        printSolution(board,n);
        return;
    }

    //Q1 ko sari row ke andar try kro
    for(int row =  0 ; row<n ; row++){

        if(isSafe(row,col,board,n)){
            //rakh do 
            board[row][col]='Q';
            solve(board,col+1,n);
            //backtrack
            board[row][col]='_';
        }
    }
}


int main(){
    int n = 4;
    vector<vector<char>> board(n,vector<char>(n,'_'));
    int col = 0;
    solve(board,col,n);
}