#include <iostream>
#include <vector>
using namespace std;

/**
 * Simple Subset Generation (Power Set)
 * Time Complexity: O(2^N)
 */

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int total = 1 << n; // 2^n
    for (int i = 0; i < total; i++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) cout << arr[j] << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}
