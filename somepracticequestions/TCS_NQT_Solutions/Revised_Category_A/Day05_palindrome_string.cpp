#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Palindrome String (Revised)
 * Logic: Two-pointer approach from both ends.
 */

bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    if (isPalindrome(s)) cout << "Palindrome String" << endl;
    else cout << "Not a Palindrome String" << endl;
    
    return 0;
}
