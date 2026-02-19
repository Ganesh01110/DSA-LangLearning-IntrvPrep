#include<iostream> 
using namespace std;

int factorial(int n) {
    
    //base case
    if(n==0)
        return 1;

    int smallerProblem = factorial(n-1);   
    int biggerProblem = n * smallerProblem;

    return biggerProblem;
}

int power(int n){
    //base case
    if(n ==0)
     return 1;

    int smallerProblem = power(n-1);   
    int biggerProblem = 2 * smallerProblem;

    return biggerProblem;
}

int main() {

    int n;
    cin >> n;

    int ans = factorial(n);

    int ans1 = power(n);

    cout << ans << endl;
    cout << ans1 << endl;

    return 0;
}

// a recursion always has tw parts 
//-base case -> shows where to stop (writing return is mandatory ), if base case absent it shows segmentation fault
//-recursion relation -> establishes connection between big an dsmall problem