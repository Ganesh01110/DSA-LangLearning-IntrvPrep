// Problem Statement: "Given a string, check if the string is palindrome or not."  A string is said to be palindrome if the reverse of the string is the same as the string.

// Example 1:
// Input: Str =  “ABCDCBA”
// Output: Palindrome
// Explanation: String when reversed is the same as string.



// Approach:

// Run a for loop till half the length of the string in order to check the first and last character of the string.

// And check if the first and last elements of the string are equal. And then move both pointers first pointer forward and last pointer backward.

// Here we are achieving this with the help of ‘i’ which moves with them for a loop. First element can be get by str[i] and last element by str[str.length() - i - 1]). If this condition gets executed then it is not palindrome and returns false.

// If the loop ends after traversing elements till half of the length then, it is Palindrome and returns false.

#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {

        int left = 0, right = s.length()-1;
        while(left<right)
        {
            if(!isalnum(s[left])) 
                left++;
            else if(!isalnum(s[right])) 
                right--;
            else if(tolower(s[left])!=tolower(s[right])) 
                return false;
            else {
                left++; 
                right--;
            }
        }
        return true;

}
int main() {

  string str = "ABCDCBA";
  bool ans = isPalindrome(str);

  if (ans == true) {
    cout << "Palindrome";
  } else {
    cout << "Not Palindrome";
  }
  return 0;
}