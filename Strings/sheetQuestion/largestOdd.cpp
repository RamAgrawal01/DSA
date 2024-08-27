#include<iostream>
using namespace std;

string largestOdd(string str){
    for(int i = str.length()-1 ; i>=0 ; i--){
        if((str[i]-'0') % 2 != 0){
            return str.substr(0,i+1);
        }
    }
    return "";
}

int main(){
    string str = "504";
    cout<<"Largest odd number is: "<<largestOdd(str);
}