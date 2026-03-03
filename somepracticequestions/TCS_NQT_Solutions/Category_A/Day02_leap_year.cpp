#include <iostream>
using namespace std;

/**
 * Leap Year Check
 */

int main() {
    int year;
    if (!(cin >> year)) return 0;
    
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        cout << "Leap Year" << endl;
    } else {
        cout << "Not a Leap Year" << endl;
    }
    
    return 0;
}
