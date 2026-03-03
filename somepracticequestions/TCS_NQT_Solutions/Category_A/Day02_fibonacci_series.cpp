#include <iostream>
#include <vector>
using namespace std;

/**
 * Fibonacci Series up to N terms
 * Time Complexity: O(N)
 */

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    if (n <= 0) return 0;
    
    long long a = 0, b = 1;
    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";
    
    for (int i = 3; i <= n; i++) {
        long long next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }
    cout << endl;
    
    return 0;
}
