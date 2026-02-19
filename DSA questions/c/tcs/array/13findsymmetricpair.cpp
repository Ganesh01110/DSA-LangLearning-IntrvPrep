//  Given an array of pairs, find all the symmetric pairs in the array.

//  Example 1:
// Input: (1,2),(2,1),(3,4),(4,5),(5,4)
// Output: (2,1) (5,4)
// Explanation: Since (1,2) and (2,1) are symmetric pairs and (4,5) and (5,4) are symmetric pairs.

// Solution 1: Brute force

// Intuition: For every pair check in the vector pair if the symmetric pair is present or not.

// Approach:

// First use a for loop and traverse through every pair in the vector.
// Then use another for loop and check if the symmetric pair of that pair is present in the rest of the vector or not.
// If the symmetric pair is present print the pair and break from the second for loop.so as to avoid repetitive printing of answers in case of duplicate pair.
// If the symmetric pair is not present,move to the next pair.

#include<bits/stdc++.h>

using namespace std;
int main() {
  int n = 5;
 
  int arr[][2] = {{1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 4}}; 
  cout << "The Symmetric Pairs are: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j][0] == arr[i][1] && arr[j][1] == arr[i][0]) {
        cout << "(" << arr[i][1] << " " << arr[i][0] << ")" << " ";
        break;
      }
    }
  }

}

// The Symmetric Pairs are:
// (2 1) (5 4)

// Time Complexity: O(N*N).

// Space Complexity: O(1).