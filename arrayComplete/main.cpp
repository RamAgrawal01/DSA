#include <iostream>

// Function to find the maximum of three numbers
int max_of_three(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int num1, num2, num3;

    // Input three numbers
    std::cout << "Enter three numbers: ";
    std::cin >> num1 >> num2 >> num3;

    // Find the maximum of the three numbers
    int max = max_of_three(num1, num2, num3);

    // Output the maximum number
    std::cout << "The maximum of the three numbers is: " << max << std::endl;

    return 0;
}
