#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Maximum Subarray Sum (Kadane's Algorithm)
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

long long maxSubarraySum(vector<int>& arr) {
    long long maxi = LONG_MIN, sum = 0;
    for (int x : arr) {
        sum += x;
        maxi = max(maxi, sum);
        if (sum < 0) sum = 0;
    }
    return maxi;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << maxSubarraySum(arr) << endl;
    
    return 0;
}
