#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/**
 * Vowel and Consonant Count
 * Time Complexity: O(N)
 */

int main() {
    string s;
    if (!getline(cin, s)) return 0;
    
    int vowels = 0, consonants = 0;
    for (char c : s) {
        if (!isalpha(c)) continue;
        char lower = tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            vowels++;
        } else {
            consonants++;
        }
    }
    
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    
    return 0;
}
