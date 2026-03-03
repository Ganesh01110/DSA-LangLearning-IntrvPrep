#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Frequency of Each Element in Array
 * Time Complexity: O(N log N) with map or O(N) with unordered_map
 */

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    
    for (auto it : freq) {
        cout << it.first << ": " << it.second << endl;
    }
    
    return 0;
}
