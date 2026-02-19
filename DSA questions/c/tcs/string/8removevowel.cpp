// Problem Statement: Given a String, write a program to remove vowels from a given String.

// Input: Str = “I am very happy today”
// Output:  m vry happy tdy
// Explanation: All vowels are removed from the given String.

// Approach:  Go through every character of the string, and if a vowel is found then replace it with a removed vowel string.

#include <iostream>
#include <string.h>
using namespace std;
// Function to remove vowels from a string
string RemoveVowels(string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
    {
      str = str.substr(0, i) + str.substr(i + 1);
      i--;
    }
  }
  return str;
}
int main()
{
  string str = "take u forward";
  cout <<"String after removing the vowels \n" <<RemoveVowels(str) << endl;
  return 0;
}