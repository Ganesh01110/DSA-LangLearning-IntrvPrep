// Problem Statement: Given a string, calculate the frequency of characters in a string.

// Examples:

// Example 1:
// Input: takeuforward
// Output: a2 d1 e1 f1 k1 o1 r2 t1 u1 w1 
// Explanation: Count of every character of string is printed.

// Example 2:
// Input: articles
// Output: a1 c1 e1 i1 l1 r1 s1 t1 
// Explanation: Count of every character of string is printed.

// Solution 1: 

// Approach: Sort the string and print the consecutive elements count.

// For eg. 

// Str = articles

// Sort the string first, the sorted string is aceilrst

// Now, print the occurrences of every consecutive element - a1 c1 e1 i1 l1 r1 s1 t1

#include <iostream>
#include <algorithm>
using namespace std;
void Printfrequency(string str)
{
  sort(str.begin(), str.end());
  char ch = str[0];
  int count = 1;
  for (int i = 1; i < str.length(); i++)
  {
    if (str[i] == ch)
      count++;
    else
    {
      cout << ch << count << " ";
      count = 1;
      ch = str[i];
    }
  }
  cout << ch << count << " ";
}

int main()
{
  string str = "takeuforward";
  Printfrequency(str);
  return 0;
}

// Time Complexity: O(nlogn) since sorting function requires nlogn iterations.

// Space Complexity: O(1)