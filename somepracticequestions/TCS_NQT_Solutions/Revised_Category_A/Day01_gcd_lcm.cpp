#include <iostream>
using namespace std;

/**
 * GCD and LCM (Revised)
 * Logic: GCD using Euclidean Algorithm, LCM = (a*b)/GCD.
 */

long long getGCD(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long a, b;
    cout << "Enter two numbers: ";
    if (!(cin >> a >> b)) return 0;
    
    long long gcd = getGCD(a, b);
    long long lcm = (a * b) / gcd;
    
    cout << "GCD: " << gcd << endl;
    cout << "LCM: " << lcm << endl;
    
    return 0;
}
