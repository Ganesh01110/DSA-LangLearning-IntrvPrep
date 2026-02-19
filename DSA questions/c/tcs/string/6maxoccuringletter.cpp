// Example 1:
// Input: str = “takeuforward”
// Output: a
// Explanation: The character 'a' and 'r’ have the same  maximum occurrence i.e 2. Hence we can print any one of them

// Example 2:
// Input: str = “apple”
// Output: p
// Explanation: The character

// Approach:
// We can store the frequency of characters encountered in the string in the form of their ASCII values. The range of ASCII values can lie from 0 to 256, so we can use an array of size 256 and initialize all the indexes with 0.

#include <iostream>
using namespace std;
char maxOccurringChar(string str) {
   char ans;
   int maxfreq = 0, n = str.length();
   int count[256] = {0};
   for (int i = 0; i < n; i++) {
      count[str[i]]++;
      if (count[str[i]] > maxfreq) {
         maxfreq = count[str[i]];
         ans = str[i];
      }
   }
   return ans;
}
int main() {
   string str = "takeuforward";
   cout << "Maximum occurring character is " << maxOccurringChar(str) << endl;
}