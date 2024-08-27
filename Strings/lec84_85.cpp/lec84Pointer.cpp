#include<iostream>
using namespace std;

//pointers stores the address of other variable

int main(){
    // int a = 5;
    // int *ptr = &a;
    // cout<<"printing ptr: "<<ptr<<endl;
    // cout<<"priting *ptr: "<<*ptr<<endl;
    // cout<<"printing &ptr: "<<&ptr;

    int a = 5;
    int *ptr = &a;
    cout<<"Value of address at integer: "<<ptr<<endl;
    cout<<sizeof(ptr)<<endl;


    char ch = 'a';
    char *ctr = &ch;
    cout<<"Value of address at char: "<<ctr<<endl;
    cout<<sizeof(ctr)<<endl;

    double d = 1.03;
    double *dtr = &d;
    cout<<"Value of address at double: "<<dtr<<endl;
    cout<<sizeof(dtr)<<endl;

}