#include<iostream>
using namespace std;

void util(int *p)
{
    // p = p+1;
    *p=*p+1;
}

int main(){
    int a = 5;
    int *p = &a;

    cout<<"Before: "<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"*p: "<<*p<<endl;

    util(p);

      cout<<"After: "<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"p: "<<p<<endl;
    cout<<"*p: "<<*p<<endl;

    cout<<a<<endl;
    return 0;
}