#include <iostream>

using namespace std;

void fibonacciIterative(int n) {
    int a = 0, b = 1, c;
    cout << "Fibonacci Series: " << a << " " << b << " ";
    for (int i = 2; i < n; ++i) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
    } else {
        fibonacciIterative(n);
    }

    return 0;
}
