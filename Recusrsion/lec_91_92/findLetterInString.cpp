#include<iostream>
using namespace std;

bool checkKey(string str , int i ,int n , char key ){
    //base case
    if(i>=n){
        //key not found
        return false;
    }
    //1 case
    if(str[i]==key){
        return true;
    }
    //recurision
    return checkKey(str , i+1 , n , key);
}

int main(){
    string str = "lovebabbar";
    int n = str.length();
    char key = 'z';
    bool ans = checkKey(str ,0, n , key);
    cout<<"answer is: "<<ans<<endl;
    return 0;

    
}