#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Sliding Window: Maximum sum of subarray of size K
 * Time Complexity: O(N)
 */

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    if (n < k) return 0;
    
    long long currentSum = 0;
    for (int i = 0; i < k; i++) currentSum += arr[i];
    
    long long maxSum = currentSum;
    for (int i = k; i < n; i++) {
        currentSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, currentSum);
    }
    
    cout << maxSum << endl;
    
    return 0;
}
