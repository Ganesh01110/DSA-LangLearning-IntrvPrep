#include <iostream>
#include <string>
using namespace std;

/**
 * String Reversal (Revised)
 * Logic: Manual swap from ends to center.
 */

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    
    cout << "Reversed String: " << s << endl;
    return 0;
}
