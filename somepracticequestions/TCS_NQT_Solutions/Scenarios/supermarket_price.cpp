#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * SCENARIO: Supermarket Purchase
 * PROBLEM: A person buys product 'X'. The price they pay is the product of 
 * all digits in the value of N (N is given). Find the price.
 * 
 * CORE PATTERN: Digit Extraction
 * COMPLEXITY: O(log N) - based on number of digits.
 */

long long getDigitProduct(long long n) {
    if (n == 0) return 0;
    long long prod = 1;
    while (n > 0) {
        prod *= (n % 10);
        n /= 10;
    }
    return prod;
}

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    
    cout << getDigitProduct(n) << endl;
    
    return 0;
}
