#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Array Rotation (Revised)
 * Logic: Reverse segments to rotate in O(n) time and O(1) space.
 */

void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;
    k %= n; // Effective rotations
    
    // Left Rotation by k
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    int n, k;
    cout << "Enter array size: "; cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << "Enter rotation count (k): "; cin >> k;
    
    rotateArray(arr, k);
    
    cout << "Rotated Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    return 0;
}
