#include<iostream>
using namespace std;

bool isIsomorphicString(string s , string t){
    //create a hash for mapping each char of string s1 with s2;
    int hash[256] = {0};
    //stores if t[i] char already mapped with s[i];
    bool isTCharMapped[256] = {0};

    for(int i = 0; i < s.length(); i++){
        if(hash[s[i]] == 0 && isTCharMapped[t[i]] == 0){
            // map s[i] to t[i]
            hash[s[i]] = t[i];
            isTCharMapped[t[i]] = true;
        } else {
            // check if the current mapping is consistent
            if(hash[s[i]] != t[i]){
                return false;
            }
        }
    }

    return true;
}


int main(){
    string s1 = "aab";
    string s2 = "xxy";
    int ans=isIsomorphicString(s1 , s2);

    if(ans==0){
        cout<<"Not a isomorphic";
    }
    else{
        cout<<"Strings ar isomorphic";
    }
}