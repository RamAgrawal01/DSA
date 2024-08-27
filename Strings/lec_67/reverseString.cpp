#include<iostream>
#include <cstring> // Include for strlen functio
using namespace std;

void reverseCharArray(char ch[]){
    int i = 0;
    int n = strlen(ch); // Get the length of the string
    int j = n - 1;

    // Reverse the array
    while(i <= j){
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
}

int main(){
    char ch[50];
    cout<<"Enter the string for reverse: ";
    cin.getline(ch,50);
    reverseCharArray(ch);
    cout<<"After reversal process: "<<ch;
}
