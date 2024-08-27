#include<iostream>
using namespace std;

string reverseOnlyLetters(string s){
    int i = 0;
    int j = s.length();

    while(i<=j){
        if(isalpha(s[i]) && isalpha(s[j])){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        else if(!isalpha(s[i])){
            i++;
        }
        else{
            j--;
        }
    }
    return s;

}


int main(){
    string str = "A&x#";
    string ans = reverseOnlyLetters(str);
    cout<<"After reverse only letter is: "<<ans;
}