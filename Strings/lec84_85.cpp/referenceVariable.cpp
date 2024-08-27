#include<iostream>
using namespace std;
//safety more because we cannot create null reference variable like pointer
//
int main(){
    int a = 5;
    //creating a reference variable
    int &b = a;  

    cout<<"Printing a: "<<a<<endl;
    cout<<"printing b: "<<b<<endl;
}