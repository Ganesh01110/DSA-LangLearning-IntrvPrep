// 1281. Subtract the Product and Sum of Digits of an Integer
// Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 

// Example 1:

// Input: n = 234
// Output: 15 
// Explanation: 
// Product of digits = 2 * 3 * 4 = 24 
// Sum of digits = 2 + 3 + 4 = 9 
// Result = 24 - 9 = 

class Solution {
public:
    int subtractProductAndSum(int n) {
      int k=n;
      int sum=0;
      int prod=1;
      while(k!=0){
        int lastdig=k%10;
        sum=sum+lastdig;
        prod=prod*lastdig;

        k=k/10;
      }  

     int result= (prod-sum);
     return result;
    }
};