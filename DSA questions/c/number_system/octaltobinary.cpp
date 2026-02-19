// Problem Statement: Given an Octal Number, convert it into Binary Number.

// Example 1:
// Input: 345
// Output: 011100101
// Explanation: Binary equivalent of given Octal expressionis 011100101

// Approach: 

// For Octal to Binary Conversion, we will first convert Octal Number System to Decimal Number System and then convert Decimal Number System to Binary Number System.

// For Octal to Decimal Conversion

// We will take every digit of the number and multiply it with 8 raised to power i which will increase by 1 when we move to the next digit and then add it to sum. This task is repeated until n becomes 0.

// For Decimal to Binary Conversion

// For Decimal to Binary Conversion, we will divide the given number by 2 ( Since the Binary Numbers System has 2 digits in use ) repeatedly, and its remains will be stored till the number becomes zero.


#include <iostream>
#include <math.h>
using namespace std;
int OctaltoDecimal(int Octal)
{
    int Decimal = 0;
    int i = 0;
    while (Octal != 0)
    {
        int rem = Octal % 10;
        Decimal += rem * pow(8, i);
        i++;
        Octal /= 10;
    }
    return Decimal;
}
int DecimaltoBinary(int decimal)
{
    int Binary = 0;
    int i = 0;
    while (decimal != 0)
    {
        int rem = decimal % 2;
        Binary += (rem * pow(10, i));
        i++;
        decimal = decimal / 2;
    }
    return Binary;
}
int main()
{
    int Octal = 345;
    int Decimal = OctaltoDecimal(Octal);
    cout << "The binary conversion of the given octal number is "<<DecimaltoBinary(Decimal) << endl;
    return 0;
}

// Output:

// The binary conversion of the given octal number is 11100101

// Time Complexity: O(log n) where n is the number 

// Space Complexity: O(1)