// calculate the sum of n terms of fibbonacci series
// note fib(0)=1
// fib(1)=1
// input: n=5
// op:7   =. 0+1+1+2+3+5+8...

#include <iostream>
using namespace std;

int fibonacci(int n) {
    int a = 0, b = 1, sum=1;
    if (n < 0) {
        cout << "Incorrect input" << endl;
        return -1; // or any error code you prefer
    } else if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } else {
        for (int i = 2; i < n; ++i) {
            int c = a + b;
            sum += c;
            a = b;
            b = c;
        }
        return sum;
    }
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}