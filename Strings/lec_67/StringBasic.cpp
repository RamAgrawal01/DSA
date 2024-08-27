#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin , str);
    cout<<str<<endl;
    cout<<"length: "<<str.length()<<endl;
    cout<<"is empty: "<<str.empty()<<endl;
    str.push_back('A');
    cout<<"After push back: "<<str<<endl;
    str.pop_back();
    cout<<"After pop back: "<<str<<endl;
    cout<<str.substr(0,6)<<endl;

    //comapare function:
    // string str1,str2;
    // cout<<"Enter ist string: ";
    // getline(cin,str1);
    // cout<<"Enter 2nd string: ";
    // getline(cin,str2);

    // if(str1.compare(str2)==0){
    //     cout<<"Both string are same"<<endl;
    // }
    // else{
    //     cout<<"Both are not same"<<endl;
    // }
    

    // string x = "abcd";
    // string y = "bcda";
    // cout<<x.compare(y)<<endl; //return -1 if character of ist string is small and return +1  for vice versa


    // //find function
    // string sentence = "Hello Jee kaise ho sare";
    // string target = "Everyone";

    // if(sentence.find(target)==string::npos){
    //     cout<<"Not Found"<<endl;
    // }

    //replace function
    string str6 = "This is my first message";
    string word = "third";
    str6.replace(11,5,word);
    cout<<str6<<endl;

    //erase function
    string str7 = "ABCDEFGHIJKLMNOPQRS";
    str7.erase(4,5);
    cout<<str7;

    return 0;
 }