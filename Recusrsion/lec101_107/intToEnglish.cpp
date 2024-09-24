#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Define pairs for all numbers and their English words
const vector<pair<int, string>> mp = {
    {1e9, "Billion"}, {1e6, "Million"}, {1e3, "Thousand"}, 
     {100, "Hundred"}, 
    {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"},
    {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, 
    {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"},
    {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, 
    {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"},
    {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}
};

string numberToWords(int n){
    //base case
    if(n==0){
        return "zero";
    }

    for(auto it:mp){
        //firstly check from which pair number is just greater
        if(n>=it.first){
            string a="";
            if(n>=100){
                a=numberToWords(n/it.first)+" ";
            }
            string b = it.second;

            string c ="";
            if(n%it.first!=0){
                c=" "+numberToWords(n%it.first);
            }
            return a+b+c;
        }
    }
    return "";
}


int main(){
    int num = 76817;
    string ans = numberToWords(num);
    cout<<ans;

}