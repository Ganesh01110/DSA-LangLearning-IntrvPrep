// Problem Statement: Given a geometric Progression (G.P) sequence with some inputs as:-

// a, first term
// r, common ratio
// n, number of terms

// Example 1:
// Input: a=1 , r=0.5 , n=3
// Output: 1.75
// Explanation: The sum of given GP Series is 1.75

// For Eg. 

// a= 2, r=2, n=4

// Initially , sum=0

// First Term , a=2 , sum=2

// Second Term , ar=4 , sum=6

// Third Term , ar2=8, sum=14

// Fourth / Last Term , ar3=16 , sum=30

// Finally , sum is 30

#include <iostream>
using namespace std;
// Function to find sum of G.P. series
float SumofGP(float a, float r, int n)
{
  float sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum = sum + a;
    a = a * r;
  }
  return sum;
}
int main()
{
  float a = 2;     // First Term of G.P.
  float r = 1.5; // Common Ration of G.P.
  int n = 4;     // Number of terms in a G.P.
  cout << "Sum of GP Series is "<<SumofGP(a, r, n);
  return 0;
}