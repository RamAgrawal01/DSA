#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

void upperCase(char arr[]) {
    int n = strlen(arr);
    for(int i = 0; i < n; i++) {
        // Check if the character is a lowercase letter
        if(arr[i] >= 'a' && arr[i] <= 'z') {
            arr[i] = arr[i] - 'a' + 'A'; // Convert to uppercase
        }
    }
}
//upper case to lower case and removal of space and other character
string lowerCase(char arr[]){
    int n = strlen(arr);
    string ans;
    for(int i =0 ; i<n;i++){
        //check if the character is uppercase letter
        if(arr[i]>='A' && arr[i]<='Z'){
            arr[i] = arr[i] -'A' + 'a';
            ans.push_back(arr[i]);
        }
    }
    return ans;
}



int main(){
    char arr[50];
    cout<<"Enter string for uppercase: ";
    cin.getline(arr,50);
    string ans = lowerCase(arr);
    cout<<ans<<endl;
}