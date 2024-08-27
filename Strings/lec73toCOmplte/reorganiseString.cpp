#include<iostream>
#include<string>
#include<climits>
using namespace std;

string reorganizeString(string s) {
    int hash[26] = {0};

    // Frequency count
    for (int i = 0; i < s.length(); i++) {
        hash[s[i] - 'a']++;
    }

    // Find the most frequent character
    char maxChar = '\0';
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (hash[i] > maxFreq) {
            maxFreq = hash[i];
            maxChar = i + 'a';
        }
    }

    // If the most frequent character is more than half of the string length, return ""
    if (maxFreq > (s.length() + 1) / 2) {
        return "";
    }

    int index = 0;
    // Place the most frequent character
    while (maxFreq > 0) {
        s[index] = maxChar;
        maxFreq--;
        index += 2;
    }

    // Reset the frequency of the most frequent character
    hash[maxChar - 'a'] = 0;

    // Place the remaining characters
    for (int i = 0; i < 26; i++) {
        while (hash[i] > 0) {
            if (index >= s.length()) index = 1;
            s[index] = i + 'a';
            index += 2;
            hash[i]--;  // Decrement frequency after placing the character
        }
    }

    return s;
}

int main(){
    string str = "geeksforgeeks";
    string ans = reorganizeString(str);
    cout<<"String is: "<<ans;
}