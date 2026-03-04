#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * String Reversal (Manual)
 * Requirement: Do not use reverse() library function.
 */

void reverseString(string &s) {
    int start = 0, end = s.length() - 1;
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

int main() {
    string s;
    if (!getline(cin, s)) return 0;
    
    reverseString(s);
    cout << s << endl;
    
    return 0;
}
