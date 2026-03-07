#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Remove Duplicates (Revised)
 * Logic: Use an unordered_set to track seen elements and preserve order.
 */

int main() {
    int n;
    cout << "Enter array size: "; cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> result;
    unordered_set<int> seen;
    
    for (int x : arr) {
        if (seen.find(x) == seen.end()) {
            result.push_back(x);
            seen.insert(x);
        }
    }
    
    cout << "Array after removing duplicates: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}
