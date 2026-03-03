#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Remove Duplicates from Sorted Array
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;
    int i = 0;
    for (int j = 1; j < arr.size(); j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int newLen = removeDuplicates(arr);
    
    for (int i = 0; i < newLen; i++) cout << arr[i] << (i == newLen-1 ? "" : " ");
    cout << endl;
    
    return 0;
}
