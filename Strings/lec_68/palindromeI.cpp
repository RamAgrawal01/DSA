#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(int i, int j, string &ans) {
    while (i <= j) {
        if (ans[i] == ans[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

bool isPalindrome(string str) {
    string ans;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ans.push_back(str[i] - 'A' + 'a');
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            ans.push_back(str[i]);
        } else if (str[i] >= '0' && str[i] <= '9') {
            ans.push_back(str[i]);
        }
    }

    // Debugging: Print each character and the length
    cout << "Ready String: " << ans << endl;

    return checkPalindrome(0, ans.length() - 1, ans);
}

int main() {
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    cout << (isPalindrome(str) ? "true" : "false") << endl;
    return 0;
}
