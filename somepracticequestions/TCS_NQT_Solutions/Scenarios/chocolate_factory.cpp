#include <iostream>
#include <vector>
using namespace std;

/**
 * SCENARIO: The Chocolate Factory
 * PROBLEM: Given an array of N integers representing packets (0 means empty), 
 * move all empty packets to the end of the line.
 * 
 * CORE PATTERN: Move Zeroes to End (Two Pointers)
 * COMPLEXITY: O(N) Time, O(1) Space
 */

void moveZeroesToEnd(int n, vector<int>& arr) {
    int nonZeroIndex = 0;
    
    // Pass 1: Move all non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex++] = arr[i];
        }
    }
    
    // Pass 2: Fill the rest with zeros
    for (int i = nonZeroIndex; i < n; i++) {
        arr[i] = 0;
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    moveZeroesToEnd(n, arr);
    
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
