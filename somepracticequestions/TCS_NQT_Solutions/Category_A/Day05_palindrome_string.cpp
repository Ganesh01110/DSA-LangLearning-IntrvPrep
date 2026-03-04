#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Palindrome String Check
 * (Without using reverse library for exam practice)
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
    if (!(cin >> s)) return 0;
    
    if (isPalindrome(s)) cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;
    
    return 0;
}
