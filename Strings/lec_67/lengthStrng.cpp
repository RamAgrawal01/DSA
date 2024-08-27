#include<iostream>
#include <cstring>
using namespace std;

int main(){
    char name[50];
    cout<<"Enter your name: ";
    cin.getline(name,50);
    int length = 0;
    int i=0;
    while(name[i] != '\0'){
        length++;
        i++;
    }
    cout<<length;

    return 0;
}