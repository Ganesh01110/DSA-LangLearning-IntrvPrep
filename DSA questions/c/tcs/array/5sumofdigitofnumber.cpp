#include <iostream>
using namespace std;

int main() {
    int number, sum = 0, remainder;

    // Read input from user
    cout << "Enter an integer: ";
    cin >> number;

    // Calculate the sum of all digits
    while (number != 0) {
        remainder = number % 10; // Get the last digit
        sum += remainder;        // Add the digit to the sum
        number /= 10;            // Remove the last digit from the number
    }

    // Print the sum of digits
    cout << "Sum of all digits: " << sum << endl;

    return 0;
}

