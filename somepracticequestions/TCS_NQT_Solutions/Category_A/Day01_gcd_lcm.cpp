#include <iostream>
using namespace std;

/**
 * GCD and LCM using Euclidean Algorithm
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / gcd(a, b);
}

int main() {
    long long a, b;
    if (!(cin >> a >> b)) return 0;
    
    cout << "GCD: " << gcd(a, b) << endl;
    cout << "LCM: " << lcm(a, b) << endl;
    
    return 0;
}
