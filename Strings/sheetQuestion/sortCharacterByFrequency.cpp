#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

string frequencySort(string s){
    //step 1 : making frequencyTable for each character
    unordered_map<char,int> freqMap;
    for(char c : s){
        freqMap[c]++;
    }

    //step2: store all characters in set
    unordered_set<char> charSet(s.begin(),s.end());

    string result;

    //step 3 for finding which character has more frquency
    while(!charSet.empty()){
        char maxFreq = 0;
        char maxChar = 0;

        for(char c: charSet){
            if(freqMap[c]>maxFreq){
                maxFreq = freqMap[c];
                maxChar = c;
            }
        }

        //append the max frequency character with maxFreq times
        result.append(maxFreq,maxChar);

        //Remove the character from the set and map so that for next iteration
        charSet.erase(maxChar);
        freqMap.erase(maxChar);
    }
    return result;
}

int main(){
    string str = "Aabb";
    string result = frequencySort(str);
    cout<<"Sorted by frequency: "<<result;
}