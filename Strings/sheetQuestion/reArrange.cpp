#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 string arrangeString(string str)
    {
        vector<char>alphabets;
        int digitSum = 0;
        
        for(char ch : str){
            if(isdigit(ch)){
                digitSum += ch- '0';
            }
            else if(isalpha(ch)){
                alphabets.push_back(ch);
            }
        }
        
        sort(alphabets.begin(),alphabets.end());
        
        for(char ch:alphabets){
            cout<<ch;
        }
        cout<<digitSum<<endl;
        
        
    }

int main() {
    string input = "AC2BEW3";
    arrangeString(input);
    return 0;
}
