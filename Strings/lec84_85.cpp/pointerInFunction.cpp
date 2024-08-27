#include<iostream>
using namespace std;

void solve(int *ptr){
    *ptr = *ptr + 10;
}

int main(){
    int a = 5;
    int *ptr = &a;
    cout<<"Value of a is before calling function: "<<a<<endl;
    solve(ptr);
    cout<<"value of a after calling function: "<<a;
}