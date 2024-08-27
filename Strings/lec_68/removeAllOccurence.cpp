#include<iostream>
using namespace std;

 string removeAllOccurences(string s, string part) {
        
        int pos = s.find(part);
        while(pos != string::npos){
            s.erase(pos,part.length());
            pos = s.find(part);
        }
        return s;
    }

int main(){
    string s = "axxxxyyyyb";
    string part = "xy";
    string ans = removeAllOccurences(s,part);
    cout<<"After removing occurences: "<<ans;
}