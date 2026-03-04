#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Binary Search
 * Time Complexity: O(log N)
 * Requirement: Array must be sorted.
 */

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, target;
    if (!(cin >> n >> target)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end()); // Binary search needs sorted array
    
    int result = binarySearch(arr, target);
    if (result == -1) cout << "Not Found" << endl;
    else cout << "Found at index " << result << " (in sorted array)" << endl;
    
    return 0;
}
