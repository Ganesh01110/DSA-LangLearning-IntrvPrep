#include <iostream>
using namespace std;

/**
 * Palindrome Number (Revised)
 * Logic: Reverse digits and compare.
 * Fix: Avoids string conversion or complex math.
 */

int main() {
    int n;
    cout << "Enter a number: ";
    if (!(cin >> n)) return 0;
    
    if (n < 0) {
        cout << "Not a Palindrome (Negative number)" << endl;
        return 0;
    }
    
    long long reversed = 0, temp = n;
    while (temp > 0) {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }
    
    if (reversed == n) cout << n << " is a Palindrome Number" << endl;
    else cout << n << " is not a Palindrome Number" << endl;
    
    return 0;
}
