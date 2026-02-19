#include <iostream>
using namespace std;

int main() {
    int number, originalNumber, reversedNumber = 0, remainder;

    // Read input from user
    cout << "Enter an integer: ";
    cin >> number;

    // Store the original number
    originalNumber = number;

    // Reverse the number
    while (number != 0) {
        remainder = number % 10;          // Get the last digit
        reversedNumber = reversedNumber * 10 + remainder; // Add the digit to the reversed number
        number /= 10;                     // Remove the last digit from the original number
    }

    // Check if the original number is equal to the reversed number
    if (originalNumber == reversedNumber) {
        cout << originalNumber << " is a palindrome." << endl;
    } else {
        cout << originalNumber << " is not a palindrome." << endl;
    }

    return 0;
}

