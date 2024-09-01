#include<iostream>
using namespace std;

void reverseString(string& str,int start , int end){
    //base case
    if(start>=end){
        return;
    }
    //ist case
    swap(str[start],str[end]);
    //recursion
    reverseString(str,start+1 , end-1);
}

int main(){
    string str = "ramagrawal";
    cout<<"String before reversing: "<<str<<endl;
    reverseString(str,0,str.length()-1);
    cout<<"String after reversing: "<<str;
}