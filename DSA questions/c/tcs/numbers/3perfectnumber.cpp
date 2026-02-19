// Problem Statement: Perfect Number. Write a program to find whether a number is a perfect number or not.

// A perfect number is defined as a number that is the sum of its proper divisors ( all its positive divisors excluding itself). 

// Example 1:
// Input: n=6
// Output: 6 is a perfect number

// Approach:

// We initialise a sum to 0.
// We can set a loop to iterate from 1 to n-1.
// In every iteration we check if n is divisible by i, if it is we add it to our sum.
// After the loop is over, we check whether the given number is equal to our sum, if it is then we the given number is a perfect number, otherwise not.

#include <iostream>

using namespace std;

bool isPerfect(int n) {

  int sum = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (n % i == 0)
      sum = sum + i;
  }
  if (sum == n)
    return true;
  else return false;
}

int main() {
  // your code goes here
  bool ex1 = isPerfect(6);
  bool ex2 = isPerfect(15);
  bool ex3 = isPerfect(28);

  if (ex1 == true) {
    cout << "6 is a perfect number" << endl;
  } else cout << "6 is not a perfect number" << endl;

  if (ex2 == true) {
    cout << "15 is a perfect number" << endl;
  } else cout << "15 is not a perfect number" << endl;

  if (ex3 == true) {
    cout << "28 is a perfect number" << endl;
  } else cout << "28 is not a perfect number" << endl;

  return 0;
}