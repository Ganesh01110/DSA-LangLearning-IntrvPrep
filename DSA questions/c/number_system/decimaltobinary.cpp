// Problem Statement: Convert decimal to binary number.

// Example 1:
// Input: N = 15
// Output: 1111
// Explanation: 15 in binary is represented as "1111".

// Intuition: Since each number can be represented by the sum of the powers of 2s, we simply have to check from 2^0 to 2^32 if the decimal number is divisible by 2^i or not.

// Approach: 

// Take an array to store the binary number.
// Now check if the decimal number is divisible by 2 or not.
// If it is divisible by 2,then ith index will be 0,else ith index will be 1.
// Now divide n by 2 and move to the next index.
// Repeat the above steps till n becomes 0.
// Now our binary number is stored in the array but in reverse order.
// Print the array in reverse order.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 28;
	int binary[32] = {0};
	int pow = 1;
	int i = 0;
	while (n) {
		binary[i] = n % 2;
		i++;
		n /= 2;
	}
	for (int ind = i - 1; ind >= 0; ind--) {
		cout << binary[ind];
	}
}

// 11100

// Time Complexity: O(logN)

// Space Complexity: O(32).