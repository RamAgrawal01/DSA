#include<iostream>
using namespace std;

int expandAroundIndex(string s , int i , int j, int n  ){
    int count = 0;
    while(i>=0 && j<n && s[i]==s[j]){
        count ++;
        i--;
        j++;
    }
    return count;
}

int countSubstring(string s){
    int count = 0;
    int  n = s.length();
    for(int i = 0 ; i<n ; i++){
        //case of odd length string
        int oddStringAnswer = expandAroundIndex(s,i,i,n );
        count = count + oddStringAnswer;

        //case of even length string
        int evenStringAnswer = expandAroundIndex(s,i,i+1,n );
        count = count + evenStringAnswer;
    }
    return count;
}

int main(){
    string str = "babad";
    cout<<countSubstring(str);
}