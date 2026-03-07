#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Binary Search (Revised)
 * Logic: O(log n) search on a sorted array.
 */

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n, target;
    cout << "Enter array size: "; cin >> n;
    vector<int> arr(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << "Enter target to search: "; cin >> target;
    int index = binarySearch(arr, target);
    
    if (index != -1) cout << "Element found at index: " << index << endl;
    else cout << "Element not found." << endl;
    
    return 0;
}
