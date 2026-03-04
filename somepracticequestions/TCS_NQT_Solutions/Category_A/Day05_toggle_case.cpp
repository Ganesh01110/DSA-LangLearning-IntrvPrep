#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/**
 * Toggle Case
 * Example: "aBcD" -> "AbCd"
 */

int main() {
    string s;
    if (!(getline(cin, s))) return 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) s[i] = tolower(s[i]);
        else if (islower(s[i])) s[i] = toupper(s[i]);
    }
    
    cout << s << endl;
    
    return 0;
}
