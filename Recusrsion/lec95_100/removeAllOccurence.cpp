#include<iostream>
using namespace std;

void removePart(string& str, const string& part) {
    // Find the position of 'part' in 'str'
    int found = str.find(part);

    // Base case: If 'part' is not found, do nothing
    if (found == string::npos) {
        return;
    }

    // Remove the first occurrence of 'part'
    str.erase(found, part.length());

    // Recursively call removePart to remove any remaining occurrences
    removePart(str, part);
}

int main() {
    string str = "daabcbaabcbc";
    string part = "abc";
    removePart(str, part);
    cout << "String after removal: " << str << endl;
    return 0;
}