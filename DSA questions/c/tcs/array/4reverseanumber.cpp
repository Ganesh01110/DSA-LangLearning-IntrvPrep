#include <iostream>
using namespace std;

int main() {
    int number, reversedNumber = 0, remainder;

    // Read input from user
    cout << "Enter an integer: ";
    cin >> number;

    // Reverse the number
    while (number != 0) {
        remainder = number % 10;          // Get the last digit
        reversedNumber = reversedNumber * 10 + remainder; // Add the digit to the reversed number
        number /= 10;                     // Remove the last digit from the original number
    }

    // Print the reversed number
    cout << "Reversed Number: " << reversedNumber << endl;

    return 0;
}
