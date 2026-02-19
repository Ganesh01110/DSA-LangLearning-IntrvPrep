// Problem Statement: Convert a binary number to a decimal number.

// Example 1:
// Input: N = 1011
// Output: 11
// Explanation: 1011 when converted to decimal number is “11”.

// Solution 1:

// Intuition: The idea is to add the appropriate power of 2 to the final answer, whenever the bit is set.

// Approach:

// Take the input as a string.
// Traverse from rightmost character to left.
// Maintain a integer base and multiply it by 2 everytime,to store values of pow(2,i).
// Now check if char is ‘1’ or ‘0’,if it is ‘1’ add base to your final answer.

#include<bits/stdc++.h>
using namespace std;
int main() {
	string s = "1011";
	int n = s.length();
	int base = 1;
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') {
			ans += base;
		}
		base *= 2;
	}
	cout << ans;
}

// Time Complexity: O(N), as we are iterating over just one for a loop.

// Space Complexity: O(1).