// Problem Statement: Given an A.P. Series, we need to find the sum of the Series.

// a = first term of A.P.

// d= common Difference of A.P.

// n= Number of Terms in  A.P.

// Input:
// n=8
// a=-2
// d=5
// Output: 124
// Explanation: -2 +3 + 8 + 13 + 18 + 23 + 28 + 33 = 124

#include <bits/stdc++.h>
using namespace std;
float sumofAp(float a, float d, int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a;
        a += d;
    }
    return sum;
}
int main()
{
    float a = 1.5, d = 3;
    int n = 5;
    cout << "Sum of Given Ap Series: " << sumofAp(a, d, n) << endl;
}