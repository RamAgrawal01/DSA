#include<iostream>
using namespace std;

int main(){
    // const int x = 5;
    // cout<<x<<endl;

    //const with pointers
    // const int *a = new int(2); //const data , non-const pointer
    // *a = 20;
    // cout<<*a<<endl;
    // delete a;
    // int b = 5;
    // a = &b;
    // cout<<*a<<endl;
    // return 0;

    const int *a = new int(2);
    cout<< *a <<endl;
    int b = 20;
    a = &b;
    cout<<*a<<endl;

}