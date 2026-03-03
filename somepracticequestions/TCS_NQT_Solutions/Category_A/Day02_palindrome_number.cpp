#include <iostream>
using namespace std;

/**
 * Palindrome Number Check
 * Strategy: Reverse the number and compare.
 * Time Complexity: O(log N)
 */

bool isPalindrome(int n) {
    if (n < 0) return false;
    long long reversed = 0;
    int temp = n;
    while (temp > 0) {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }
    return reversed == (long long)n;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    if (isPalindrome(n)) cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;
    
    return 0;
}
