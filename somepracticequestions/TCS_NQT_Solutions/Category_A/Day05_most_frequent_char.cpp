#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
 * Most Frequent Character in a String
 */

int main() {
    string s;
    if (!(getline(cin, s))) return 0;
    
    map<char, int> freq;
    for (char c : s) {
        if (c != ' ') freq[c]++;
    }
    
    char result;
    int maxi = 0;
    for (auto it : freq) {
        if (it.second > maxi) {
            maxi = it.second;
            result = it.first;
        }
    }
    
    cout << "Most Frequent: " << result << " (Count: " << maxi << ")" << endl;
    
    return 0;
}
