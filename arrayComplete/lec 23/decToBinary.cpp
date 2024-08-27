#include <iostream>
#include <cmath>

using namespace std;

void decimalToBinaryMethod1(int n) {
    // Division Method
    if (n == 0) {
        cout << 0 << endl; // Handle the case when input is 0
        return;
    }

    // Collect bits
    string binary;
    while (n > 0) {
        int bit = n % 2;
        binary = to_string(bit) + binary;
        n = n / 2;
    }

    // Print binary representation
    cout << "Binary representation: " << binary << endl;
}

int decimalToBinaryMethod2(int n) {
    // Bitwise method
    int binaryNo = 0;
    int base = 1;  

    while (n > 0) {
        int bit = n & 1;  // Get the least significant bit
        binaryNo += bit * base;  // Add the bit to the result
        base *= 10;  // Update base to the next power of 10
        n = n >> 1;  // Shift right by 1 to process the next bit
    }

    return binaryNo;
}

int main() {
    int n;
    cout << "Enter the number for conversion for method2: " << endl;
    cin >> n;

   int result= decimalToBinaryMethod2(n); // Call the function without type

   cout<<result<<endl;
}
