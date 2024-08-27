#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

void upperCase(char arr[]){
    int n = strlen(arr);
    for(int i =0 ; i<n ; i++){
        arr[i] = arr[i] - 'a' +'A';
    }
}

int main(){
    char arr[50];
    cout<<"Enter string for uppercase: ";
    cin.getline(arr,50);
    upperCase(arr);
    cout<<arr<<endl;
}