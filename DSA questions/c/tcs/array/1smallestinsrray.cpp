// Problem Statement: Given an array, we have to find the smallest element in the array.

// Examples:

// Example 1:
// Input: arr[] = {2,5,1,3,0};
// Output: 0
// Explanation: 0 is the smallest element in the array. 

// Example2: 
// Input: arr[] = {8,10,5,7,9};
// Output: 5
// Explanation: 5 is the smallest element in the array.

#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
int SmallestElement(int arr[], int n) {
  int min = arr[0];
  for (int i = 0; i < n; i++) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return min;
}
int main() {
  int arr1[] = {2,5,1,3,0};
  int n = 5;
  int min = SmallestElement(arr1, n);
  cout << "The smallest element in the array is: " << min << endl;
 
  int arr2[] =  {8,10,5,7,9};
  n = 5;
  min = SmallestElement(arr2, n);
  cout << "The smallest element in the array is: " << min;
  return 0;
}
 