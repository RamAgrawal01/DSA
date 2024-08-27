#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(char first , char second){
    return first>second;
}


int main(){
    string s = "babbar";
    sort(s.begin(),s.end()); // it convert the string in to ascendign order
    sort(s.begin(),s.end(),cmp); //it convert the string into descending order because of customComparator
    cout<<s<<endl;
   

    vector<int>v{5,3,1,2,4};
    sort(v.begin(),v.end(),cmp);
    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}