// Problem Statement: Given a string, write a program to remove all the whitespaces from the string.

// Input: str = “How are you doing”
// Output: Howareyoudoing
// Explanation: After removing all the whitespaces Howareyoudoing is the result

// Approach: 

// Iterating through all the characters and finding if there is whitespace and if found skipping it and adding the next element to our string using a count variable.

// The approach follows the following steps.

// Take a count variable that tells us the spaces seen sor far.
// Using a for loop, iterate through all the characters and check this condition.
// If the character at the current index is a whitespace or not, if not present then add the character to our string.
// Then increment the count to trace the whitespaces seen so far.
//  Now after traversing all the characters and removing all the whitespaces we have our string without whitespace.


#include <iostream>

using namespace std;

string removeSpaces(char str[]) {
  int count = 0; // spaces seen so far

  for (int i = 0; str[i]; i++)
    if (str[i] != ' ') { // if whitespace is present
      str[count] = str[i]; // remove whitespace
      count++; // increment the count
    }

  str[count] = '\0';

  return str;
}

int main() {
  char str[] = "Take you forward";
  cout << removeSpaces(str);

  return 0;
}

// Time Complexity: O(N)

// Space Complexity: O(1)