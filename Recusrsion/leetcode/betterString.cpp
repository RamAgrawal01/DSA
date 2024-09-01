//given a two strings we have to select that strign which have more district subsequences;

#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;

void generateDistinctSubsequences(string str , string output , int i , set<string>& subsequences){
    if(i>=str.length()){
        subsequences.insert(output);
        return;
    }
    //excluede the current character
    generateDistinctSubsequences(str,output,i+1,subsequences);
    //include the current character
    output.push_back(str[i]);
    generateDistinctSubsequences(str,output,i+1,subsequences);
}

int countDistinctSubsequences(string str) {
    set<string> subsequences;
    generateDistinctSubsequences(str, "", 0, subsequences);
    return subsequences.size();
}

string findBetterString(string str1, string str2) {
    int count1 = countDistinctSubsequences(str1);
    int count2 = countDistinctSubsequences(str2);
        cout<<"length of string 1: "<<count1<<endl;
        cout<<"length of string 2: "<<count2<<endl;

    if (count1 > count2) {
        return str1;
    } else if (count2 > count1) {
        return str2;
    } else {
        return str1; // If counts are equal, return str1
    }
}

int main(){
    string str1 = "gboubwd";
    string str2 = "bekoilx";

    //find the better string
    string betterString = findBetterString(str1,str2);
    cout<<"The better strign is: "<<betterString<<endl;
    return 0;
}