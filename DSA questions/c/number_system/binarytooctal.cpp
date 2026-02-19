// Problem Statement: Convert a binary number to an octal number
// Example 1:.
// Input: N = 1100110
// Output: 146
// Explanation: 1100110 when converted to octal number is “146”.

// Intuition: Since we have to convert it into an octal number, every bit should be between 0 to 7. We know that every number can be represented by the power of 2. So we will use the 4 2 1 rule, since using 4 2 1 we can make any number between 0 to 7.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s = "1100110";
	int n = s.length();
	if (n % 3 == 1) {
		s = "00" + s;
	}
	else if (n % 3 == 2) {
		s = "0" + s;
	}
	n = s.length();
	string ans = "";
	for (int i = 0; i < n; i += 3) {
		int temp = (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0') * 1;
		ans += (temp + '0');
	}
	cout << ans;
}

// Output:

// The octal equivalent of the given binary number is 146

// Time Complexity: O(n), As we are traversing through only one for a loop.

// Space Complexity: O(1).