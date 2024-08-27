#include<iostream>
using namespace std;

string expandAroundIndex(string s , int i , int j , int n ){
    
    
    while(i>=0 && j<n && s[i]==s[j]){
        i--;
        j++;
    }
    return s.substr(i+1,j-i-1);
}

string longestPalindrome(string s){
    int n = s.length();
     if(s.length()==0){
        return "";
    }
    string longestString = "";
   

    for(int i = 0 ; i<n ; i++){
        
        string oddString = expandAroundIndex(s,i,i,n);
        if(oddString.length()>longestString.length()){
            longestString = oddString;
        }
        string evenString = expandAroundIndex(s,i,i+1,n);
            if(evenString.length()>longestString.length()){
                longestString = evenString;
            }
        

    }
    return longestString;

}

int main(){
    string str = "aaaabbaa";
    string ans = longestPalindrome(str);
    cout<<"The longest palindrome substring is : "<<ans;

}