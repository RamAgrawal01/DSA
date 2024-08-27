#include<iostream>
#include<unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romanSymbols = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        // If the current value is less than the next value, subtract it from the result
        if (i + 1 < n && romanSymbols[s[i]] < romanSymbols[s[i + 1]]) {
            result -= romanSymbols[s[i]];
        } else {
            result += romanSymbols[s[i]];
        }
    }
    
    return result;
}


int main(){
    string str;
    cout<<"Enter roman number for integer: ";
    getline(cin,str);
    int ans = romanToInt(str);
    cout<<"Integer Value of "<<str<<" is: "<<ans;
}