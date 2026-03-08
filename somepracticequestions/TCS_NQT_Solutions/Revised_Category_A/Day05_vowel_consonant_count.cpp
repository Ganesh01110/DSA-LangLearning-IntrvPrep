#include <iostream>
#include <string>
using namespace std;

/**
 * Vowel and Consonant Count (Revised)
 * Logic: Check each character against a vowel set. 
 */

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    int v = 0, c = 0;
    for (char ch : s) {
        if (isalpha(ch)) {
            if (isVowel(ch)) v++;
            else c++;
        }
    }
    
    cout << "Vowels: " << v << endl;
    cout << "Consonants: " << c << endl;
    
    return 0;
}
