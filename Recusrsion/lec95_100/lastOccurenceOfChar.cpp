#include<iostream>
using namespace std;

int findIndex(string str , char target , int i){
    //base case
    if(str[i]==target){
        return i;
    }
    return findIndex(str , target , i-1);
}

int main(){
    string str = "abcddedddg";
    char target = 'd';
    int n = str.length();
    int index = findIndex(str , target ,n-1);
    cout<<target<<" is last occured at: "<<index;
    return 0;
}