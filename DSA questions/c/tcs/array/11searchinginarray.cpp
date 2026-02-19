// Problem Statement: Search an element in an array and return its position

// Example 1:
// Input: array[] = {1,2,3,4,5} k=3                                                                              Output:2                                                                                                            Explanation: The answer is 2 because 3 is present at 2nd index.

// Example 2:
// Input: array[]={6,7,9,5,3,10} k=10
// Output: 5
// Explanation: The answer is 5 because 10 is present at 5th index.

// Solution 1: Linear Search

// Intuition: Simply traverse through the array and check if k matches the element of the array, if it matches return the index of that element.

// Approach:

// Traverse through the array.
// If arr[i] matches k then return i.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 6;
	int arr[n] = {6, 7, 9, 5, 3, 10};
	int k = 10;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == k) {
			ans = i;
			break;
		}
	}
	cout <<"The element is present in " <<ans<<" index";
}

// Time Complexity: O(n)

// Space Complexity: O(1).


// Solution 2: Optimized solution(provided the array is sorted)

// Intuition: If the array is already sorted we can find the index of the element in O(logn).

// Approach:

// Use the binary search algorithm.
// Maintain two variables low and high.Initially low is 0 and high is n-1.low to high is the range of the index where the elements can possibly lie.
// Take another variable mid.mid = (low+high)/2.
// If the element at mid is less than k,then the required index should obviously be between mid+1 to r,so make l=mid+1.
// If the element at mid is greater than k,then the required index should obviously be between l to mid-1,so make r=mid-1.
// If the element at mid is equal to k then return mid.
// This way we go on reducing the range.If at some point r>l then the element is not present in the array.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 6;
	int arr[n] = {6, 7, 9, 5, 3, 10};
	int k = 10;
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] > k) {
			high = mid - 1;
		}
		else if (arr[mid] < k) {
			low = mid + 1;
		}
		else {
			ans = mid;
			break;
		}
	}
	cout << "The element is present in "<<ans<<" index";
}


// Time Complexity: O(logn).

// Space Complexity: O(1)