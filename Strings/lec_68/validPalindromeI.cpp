#include<iostream>
using namespace std;

bool checkPalindrome(string str , int i , int j){
    while(i<=j){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

bool isValidPalindrome(string str){
    int i = 0;
    int j = str.length()-1;

    while(i<=j){
        if(str[i] != str[j]){
            //ek bar i ko remove or ek bar j ko remove
            return checkPalindrome(str,i+1,j) || checkPalindrome(str,i,j-1);

        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<isValidPalindrome(str);

}
