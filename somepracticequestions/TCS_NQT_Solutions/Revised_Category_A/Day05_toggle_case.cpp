#include <iostream>
#include <string>
using namespace std;

/**
 * Toggle Case (Revised)
 * Logic: Check ASCII range and flip bits/subtract or add constant.
 */

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
    
    cout << "Toggled Case String: " << s << endl;
    return 0;
}
