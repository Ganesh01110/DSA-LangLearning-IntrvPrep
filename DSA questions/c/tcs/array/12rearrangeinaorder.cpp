// Problem Statement: Rearrange the array such that the first half is arranged in increasing order, and the second half is arranged in decreasing order
// Example 1:
// Input: 8 7 1 6 5 9
// Output: 1 5 6 9 8 7
// Explanation: First three elements are in the ascending order and next three elements are in the descending order.

// Intuition: Sort the whole array. Then print the first half of the array to get the first half in the ascending order and then print the rest of the array in the reverse order.

// Approach:

// Sort the given array.
// Print the first half of the array i.e from 0 to (n/2 -1)th index,to print the first half in the ascending order.
// Then print elements from n-1 to n/2th index to get the second half in the descending order.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>arr = {8, 7, 1, 6, 5, 9};
	int n = arr.size();
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n / 2; i++) {
		cout << arr[i] << " ";
	}
	for (int i = n - 1; i >= n / 2; i--) {
		cout << arr[i] << " ";
	}
}