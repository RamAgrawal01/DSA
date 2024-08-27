#include <iostream>
#include <string>

std::string eliminateString(std::string s) {
    int pos1, pos2;

    while (true) {
        pos1 = s.find("b");
        pos2 = s.find("ac");

        if (pos1 == std::string::npos && pos2 == std::string::npos) {
            break;  // Exit the loop if neither "b" nor "ac" is found
        }
        if (pos1 != std::string::npos) {
            s.erase(pos1, 1);  // Erase "b"
        }
        if (pos2 != std::string::npos) {
            s.erase(pos2, 2);  // Erase "ac"
        }
    }
    return s;  // Return the remaining string after removals
}

int main() {
    std::string s = "aacbaccd";  // Initial string
    std::string ans = eliminateString(s);  // Process the string
    std::cout << "After removing occurrences: " << ans << std::endl;  // Display final result
}
