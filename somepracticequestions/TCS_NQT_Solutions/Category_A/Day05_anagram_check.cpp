#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Anagram Check
 * Strategy: Frequency array for 256 characters.
 * Time Complexity: O(N)
 * Space Complexity: O(constant)
 */

bool areAnagrams(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    vector<int> freq(256, 0);
    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i]]++;
        freq[s2[i]]--;
    }
    
    for (int count : freq) {
        if (count != 0) return false;
    }
    return true;
}

int main() {
    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;
    
    if (areAnagrams(s1, s2)) cout << "Anagrams" << endl;
    else cout << "Not Anagrams" << endl;
    
    return 0;
}
