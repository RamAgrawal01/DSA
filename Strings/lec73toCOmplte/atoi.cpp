#include<iostream>
#include<climits>
using namespace std;

int myAtoi(string s){
    int i =0;
    int n = s.length();
    int sign = 1;
    long result = 0;

    //ignore leading white spaces
    while(i<n&&s[i]==' '){
        i++;
    }

    //check for sign
    if(i<n && s[i]=='+' || s[i]=='-'){
        sign = (s[i]=='-') ? -1 : 1;
        i++;
    }

    //convert digit into integer
    while(i<n && isdigit(s[i])){
        result = result*10 + (s[i]-'0');

        if(result*sign>INT_MAX) return INT_MAX;
        if(result*sign<INT_MIN) return INT_MIN;

        i++;
    }
    return result*sign;
}

int main(){
    string str = "21a";
    int result = myAtoi(str);
    cout<<"Converted into integer: "<<result;
}