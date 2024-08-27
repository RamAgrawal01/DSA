#include<iostream>
using namespace std;

bool isValidAnagram(string s , string t){
    int hash[256] = {0};

    for(int i =0 ; i<s.length() ; i++){
        hash[s[i]]++;
    }
    for(int i =0 ; i<t.length();i++){
        hash[t[i]]--;
    }
    //for checking all zeroes;
    for(int i = 0  ; i<256;i++){
        if(hash[i] != 0){
            return false;
        }
    }
    return true;
}


int main(){
    string str1 = "rat";
    string str2 = "car";
    int ans = isValidAnagram(str1 , str2);
    if(ans == 1){
        cout<<"Strings are anagram";
    }
    else{
        cout<<"Not anagram";
    }
}