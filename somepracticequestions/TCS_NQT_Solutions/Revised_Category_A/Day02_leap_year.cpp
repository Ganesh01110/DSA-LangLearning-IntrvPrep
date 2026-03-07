#include <iostream>
using namespace std;

/**
 * Leap Year Check (Revised)
 * Logic: divisible by 4, but not by 100 unless divisible by 400.
 */

int main() {
    int year;
    cout << "Enter a year: ";
    if (!(cin >> year)) return 0;
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is a Leap Year" << endl;
    } else {
        cout << year << " is not a Leap Year" << endl;
    }
    
    return 0;
}
