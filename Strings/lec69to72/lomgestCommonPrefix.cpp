#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>strs){
    string ans ;
    int i =0;
    while(true){
        char currentChar = 0;
        for(auto str : strs){
            
            if(currentChar == 0){
                currentChar = str[i];
            }
            else if(str[i]!=currentChar){
                currentChar = 0;
                break;
            }

        }
        if(currentChar==0){
            break;
        }
        ans.push_back(currentChar);
        i++;
    }
    return ans;
}

int main(){
    vector<string>strs{"flower" , "flow" ,"flight"};
    string ans = longestCommonPrefix(strs);
    cout<<"Longest common prefix: "<<ans;
}