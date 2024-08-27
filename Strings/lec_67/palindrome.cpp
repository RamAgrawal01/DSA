#include<iostream>
#include<cstring>
using namespace std;

bool isStringPalindrome(char ch[]){
    int i = 0;
    int j = strlen(ch) -1;

    while(i<=j){
        if(ch[i]==ch[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    char ch[50];
    cout<<"Enter the string for check palindrome: ";
    cin.getline(ch,50);
    // isStringPalindrome(ch);
    int ans=isStringPalindrome(ch);
    if(ans==0){
        cout<<"Not Palindrome";
    }
    else{
        cout<<"Palindrome";
    }
}