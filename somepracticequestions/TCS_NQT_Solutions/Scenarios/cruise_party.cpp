#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * SCENARIO: Cruise Party
 * PROBLEM: Given two arrays representing entry and exit times of guests,
 * find the maximum number of guests on the ship at any given time T.
 * 
 * CORE PATTERN: Sweep Line / Prefix Sum
 * COMPLEXITY: O(N) if hours are small, or O(N log N) with sorting.
 * Here we use the hour-based range approach (0-24 hours typical for NQT).
 */

int main() {
    int t; 
    cin >> t; // Total hours or size of arrays
    
    vector<int> e(t), l(t);
    for (int i = 0; i < t; i++) cin >> e[i];
    for (int i = 0; i < t; i++) cin >> l[i];
    
    int currentGuests = 0, maxGuests = 0;
    
    for (int i = 0; i < t; i++) {
        currentGuests += (e[i] - l[i]);
        maxGuests = max(maxGuests, currentGuests);
    }
    
    cout << maxGuests << endl;
    
    return 0;
}
/**
 * NOTE: If the problem provides exact entry/exit timestamps instead of count per hour,
 * you would sort both arrays and use two pointers to track concurrent guests.
 */
