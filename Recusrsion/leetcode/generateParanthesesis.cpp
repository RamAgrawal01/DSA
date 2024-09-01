#include<iostream>
#include<vector>
using namespace std;

void backtrack(string& current , int open , int close , int n , vector<string>& result){

    //base case
    if(current.length()==2*n){
        result.push_back(current);
        return;
    }

    //add "(" is there are still opem parantheses available
    if(open<n){
        current.push_back('(');
        backtrack(current,open+1,close,n,result);
        current.pop_back(); //backtrack
    }
    // recursive ')' if there are more open parantheses to close 
     if (close < open) {
        current.push_back(')');
        backtrack(current, open, close + 1, n, result);
        current.pop_back(); // backtrack
    }
}

vector<string> generateParenthesis(int n){
    vector<string>result;
    string current;
    backtrack(current , 0,0,n,result);
    return result;
}

int main(){
    int n =3;
    vector<string>result = generateParenthesis(n);
    cout<<"Combination of well formed parenthese: "<<endl;
    for(const auto combination : result){
        cout<<combination<<endl;
    }
    cout<<"Total number of combination: "<<result.size()<<endl;
    return 0;
}