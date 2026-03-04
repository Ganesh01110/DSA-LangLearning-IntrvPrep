#include <iostream>
#include <vector>
using namespace std;

/**
 * Equilibrium Index
 * Definition: Index i such that sum of elements at lower indices = sum of elements at higher indices.
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

int findEquilibrium(vector<int>& arr) {
    long long totalSum = 0;
    for (int x : arr) totalSum += x;
    
    long long leftSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        // totalSum now represents rightSum
        totalSum -= arr[i];
        
        if (leftSum == totalSum) return i;
        
        leftSum += arr[i];
    }
    return -1;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << findEquilibrium(arr) << endl;
    
    return 0;
}
