#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Anagram Check (Revised)
 * Logic: Use a frequency array of size 256 (ASCII) or 26 (lowercase).
 */

bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    vector<int> count(256, 0);
    for (int i = 0; i < s1.length(); i++) {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

int main() {
    string s1, s2;
    cout << "Enter first string: "; cin >> s1;
    cout << "Enter second string: "; cin >> s2;
    
    if (isAnagram(s1, s2)) cout << "Anagrams" << endl;
    else cout << "Not Anagrams" << endl;
    
    return 0;
}
