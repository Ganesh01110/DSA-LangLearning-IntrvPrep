// Example 1:
// Input: N = 5, array[] = {1,2,3,4,5}
// Output: 15
// Explanation: Sum of all the elements is 1+2+3+4+5 = 15

// Example 2:
// Input:  N=6, array[] = {1,2,1,1,5,1}
// Output: 11
// Explanation: Sum of all the elements is 1+2+1+1+5+1 = 11

// Approach-1: 

// Using for loop traverse through the array and while traversing  maintain  a variable for storing sum of the elements in the array.
// After completing the traversal simply print the sum.

// Time Complexity: O(n) As we traverse the array once.

// Space Complexity: O(1).

#include<bits/stdc++.h>
using namespace std;
int approach1() {
	// int n = 5;
	vector<int>arr = {1, 2, 3, 4, 5};
	int length = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += (double)arr[i];
	}
	cout <<"The sum of the elements of the array is "<< sum;
}

// approach-2
// “accumulate” is used to calculate the sum of all the elements in the array. 
// Time Complexity: O(n).

// Space Complexity: O(1).

int approach2() {

	int n = 5;
	int arr[] = {1, 2, 3, 4, 5};
	int initialSum = 0;
	cout <<"The sum of the elements of the array is ";
	cout<<accumulate(arr, arr + n, initialSum);

}

int main() {
    approach1();
    approach2();
}