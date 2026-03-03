#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Second Largest Element in Array
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * Strategy: Single pass, keep track of first and second max.
 */

int findSecondLargest(int n, vector<int>& arr) {
    if (n < 2) return -1;
    
    int first = INT_MIN, second = INT_MIN;
    for (int x : arr) {
        if (x > first) {
            second = first;
            first = x;
        } else if (x > second && x != first) {
            second = x;
        }
    }
    return (second == INT_MIN) ? -1 : second;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int result = findSecondLargest(n, arr);
    if (result == -1) cout << "No second largest number" << endl;
    else cout << result << endl;
    
    return 0;
}
