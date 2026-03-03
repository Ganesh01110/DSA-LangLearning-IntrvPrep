#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Array Rotation (Left) by K positions
 * Optimized Solution using Triple Reverse
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

void rotateLeft(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    if (k == 0) return;
    
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    rotateLeft(arr, k);
    
    for (int i = 0; i < n; i++) cout << arr[i] << (i == n-1 ? "" : " ");
    cout << endl;
    
    return 0;
}
