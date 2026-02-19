#include <iostream>
using namespace std;

int main() {
    int number, originalNumber, sum = 0, remainder;

    // Read input from user
    cout << "Enter an integer: ";
    cin >> number;

    // Store the original number
    originalNumber = number;

    // Reverse the number
    while (number != 0) {
        remainder = number % 10;          // Get the last digit
        sum = sum+(remainder*remainder*remainder); // add remainder by making cube
        number /= 10;                     // Remove the last digit from the original number
    }

    // Check if the original number is equal to the sum
    if (originalNumber == sum) {
        cout << originalNumber << " is a armstrog." << endl;
    } else {
        cout << originalNumber << " is not a armstrog." << endl;
    }

    return 0;
}
