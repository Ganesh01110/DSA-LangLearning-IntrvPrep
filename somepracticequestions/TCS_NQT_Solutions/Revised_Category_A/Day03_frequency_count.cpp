#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Frequency Count (Revised)
 * Logic: Use a hash map to count occurrences in O(n) average time.
 */

int main() {
    int n;
    cout << "Enter array size: ";
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    unordered_map<int, int> freq;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    
    cout << "Frequency of elements: " << endl;
    for (auto const& [val, count] : freq) {
        cout << val << " : " << count << endl;
    }
    
    return 0;
}
