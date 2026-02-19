
// Problem Statement: Reverse a String. Write a program that reverses a given string (in-place).

// Solution 1: Using Stack

// Pre-req: Stack Data Structure

// Intuition: Stack is a Last-In-First-Out (LIFO) data structure. If we iterate over the string and push each character from start to end, the stack will contain the string in a reverse way.

// Approach: 

// Take an empty stack
// Iterate over the given string from start to end.
// In each iteration, push the character at index i to the stack.
// After the first loop is completed, set a while loop till the stack is non-empty.
// Pop the character at the stack and start re-assigning the string.

#include <bits/stdc++.h>

using namespace std;

int main() {

  string str = "HELLO";
  stack < char > st;
  int n = str.length();

  for (int i = 0; i < n; i++) {
    st.push(str[i]);
  }

  int j = 0;
  while (!st.empty()) {
    char elem = st.top();
    st.pop();
    str[j] = elem;
    j++;
  }

  cout << "The reversed string is- " << str;

}

// Time Complexity: O(N)

// Reason: We iterate for the length of the string two times.

// Space Complexity: O(N)

// Reason: We are using an external stack