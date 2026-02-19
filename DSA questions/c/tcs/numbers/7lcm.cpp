// Example 1:
// Input: num1 = 4,num2 = 8
// Output: 8

// Find gcd using brute force.
// Traverse from 1 to min(a,b).
// And check if i is divisible by both a and b.If yes store it in the answer.
// Find the maximum value of i which divides both a and b.
// To find lcm simply divide (a*b) by gcd of a and b.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a = 4, b = 8;
	int gcd;
	for (int i = 1; i <= min(a, b); i++) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}
	}
	int lcm = (a * b) / gcd;
	cout <<"The LCM of the two given numbers is "<<lcm;

}

// Time Complexity: O(N).

// Space Complexity: O(1).