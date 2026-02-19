// given 2 integer,find sum of cubes all numbers in the range of n & m 
// input = 4 n 9
// op=4^3+5^3+6^3+7^3+8^3+9^3

#include <iostream>

int cube(int n){
    int cube=n*n*n;
    return cube;
}

int main() {
    int n = 4, m = 9;
    int sum = 0;

    for (int i = n; i <= m; i++) {
        sum += cube(i);
    }

    std::cout << "Sum of cubes of all numbers in the range " << n << " to " << m << " is: " << sum << std::endl;

    return 0;
}