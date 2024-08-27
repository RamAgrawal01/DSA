#include<iostream>
using namespace std;

int main(){
    int arr[4] ={12,20,16,18};

    // cout<<*arr<<endl;
    // cout<<*arr+1<<endl;
    // cout<<*(arr+1)<<endl;
    // cout<<*(arr+2)<<endl;
    // cout<<"*(arr+3)=: "<<*(arr+3)<<endl;
    // cout<<arr[3]<<endl;
    // cout<<3[arr]<<endl;

   // pointer in character array
    // char ch[10] = "Babbar";
    // char *c = ch;
    // cout<<c<<endl;

    char name[10] = "sherBano";
    char *cptr = &name[0];

    cout<<"printing name: "<<name<<endl;             //sherbano
    cout<<"printing &name: "<<&name<<endl;          //adddress of fist char
    cout<<"printing *(name+3): "<<*(name+3)<<endl;  //name[3] // r
    cout<<"printing cptr: "<<cptr<<endl;   //sherbano
    cout<<"printing &cptr: "<<&cptr<<endl;  //address of cptr
    cout<<"printing *(cptr+3): "<<*(cptr+3)<<endl; //cptr[3]   r
    cout<<"printing cptr+2: "<<cptr+2<<endl; // erBano
    cout<<"printing *cptr: "<<*cptr<<endl;  //s
    cout<<"printing cptr+8: "<<cptr+8<<endl; //blank

    char ch='k';
    char* cpt = &ch; //it return k with some garbage value
    cout<<cpt<<endl;

    char firstName[10] = "Ram";
    cout<<firstName<<endl;
    
}
