// Problem Statement: Check if the given year is a leap year or not.

// Examples:

// Example 1:
// Input: 1996
// Output: Yes
// Explanation: Since 1996 is a leap year answer is “Yes”.

// Approach: Check if the year is divisible by 4 or 400 but not by 100 then it is a leap year.

#include<bits/stdc++.h>
using namespace std;
bool yyear(int year)
{
    if(year % 400 == 0)
    return true;
    if(year % 100 == 0)
    return false;
    if(year % 4 == 0)
    return true;
    return false;
}
int main()
{
    int year=1996;
    if(yyear(year))
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}