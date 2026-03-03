#include <iostream>
using namespace std;

/**
 * Arithmetic and Geometric Progressions
 */

void solveAP(double a, double d, int n) {
    cout << "AP Series: ";
    for (int i = 0; i < n; i++) {
        cout << a + i * d << " ";
    }
    cout << endl;
}

void solveGP(double a, double r, int n) {
    cout << "GP Series: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        a *= r;
    }
    cout << endl;
}

int main() {
    int type, n;
    double a, ratio_diff;
    
    // 1: AP, 2: GP
    if (!(cin >> type >> a >> ratio_diff >> n)) return 0;
    
    if (type == 1) solveAP(a, ratio_diff, n);
    else if (type == 2) solveGP(a, ratio_diff, n);
    
    return 0;
}
