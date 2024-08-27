#include<iostream>
#include <cstring>
using namespace std;

void replaceSpace(char sentence[]){
    int i = 0;
    int n = strlen(sentence);
    for(int i=0 ; i<n;i++){
        if(sentence[i]==' '){
            sentence[i] = '@';
        }
    }
}

int main(){
    char ch[50];
    cout<<"Enter the string for replace space: ";
    cin.getline(ch,50);
    replaceSpace(ch);
    cout<<"After replace space: "<<ch;
}