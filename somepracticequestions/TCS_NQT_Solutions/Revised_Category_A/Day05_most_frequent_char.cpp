#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Most Frequent Character (Revised)
 * Logic: Use a frequency array to count occurrences of each character.
 */

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    vector<int> freq(256, 0);
    int maxFreq = 0;
    char res = ' ';
    
    for (char c : s) {
        freq[(unsigned char)c]++;
        if (freq[(unsigned char)c] > maxFreq) {
            maxFreq = freq[(unsigned char)c];
            res = c;
        }
    }
    
    cout << "Most Frequent Character: " << res << " (Occurs " << maxFreq << " times)" << endl;
    
    return 0;
}
