// Problem Statement: Given a string, write a program to count the number of vowels, consonants, and spaces in that string.

// Example 1:
// Input: string str=”hi this is Awesome”
// Output: 
// Vowels: 10
// Consonants: 11
// White spaces: 4

// Approach:

// Convert the given string into lowercase for uniformity while counting vowels,consonants,whitespaces.
// This can be done by using towlower() and .toLowerCase() in C++ and Java respectively.
// Traverse the entire modified string by applying the following conditions:
// If any vowel then increment the vowel counter

// Else if any consonant then increment the consonant counter else if any whitespace then increment the whitespace counter


#include<bits/stdc++.h>

using namespace std;
int solve(string str, int length) {
  int vowels = 0, consonants = 0, whitespaces = 0;
  for (int i = 0; i < length; i++) // converting given string to lowercase
  {
    str[i] = towlower(str[i]);
  }
  for (int i = 0; i < length; i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
      vowels++;
    else if (str[i] >= 'a' && str[i] <= 'z')
      consonants++;
    else if (str[i] == ' ')
      whitespaces++;
  }

  cout << "Vowels: " << vowels << "\n";
  cout << "Consonants: " << consonants << "\n";
  cout << "White Spaces: " << whitespaces << "\n";

}
int main() {
  string str = "Take u forward is Awesome";
  int length = str.length();
  solve(str, length);
  return 0;
}