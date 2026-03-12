#include <iostream>
using namespace std;

int powerbyrecursion(int n, int p){
    if(p==0) return 1;
    if(p==1) return n;

    return n*powerbyrecursion(n,p-1);

}

int factorialbyrecursion(int n){
 if(n==0 || n==1) return 1;

 return n*factorialbyrecursion(n-1);
}

int fastPower(int n, int p){
    if(p==0) return 1;

    int half = fastPower(n, p/2);

    if(p%2==0)
        return half * half;
    else
        return n * half * half;
}

int sumoffirstN(int n){
    if (n==0) return 0;

    return n+sumoffirstN(n-1);
}

int sumofdigits(int n){
    if(n==0) return 0;

    return (n%10) + sumofdigits(n/10);
}

int reversenum(int n , int rev=0){
    if(n==0) return rev;
    rev=rev*10+(n%10);
    return reversenum(n/10 , rev);
}

int main(){
    int n , p;
    cout<<"enter a number: ";
    if(!(cin>>n)) return 0;

    // int fact= factorialbyrecursion(n);
    // cout<<"factorial of "<<n<<" is: "<<fact<<endl;

    int sumofn= sumoffirstN(n);
    cout<<"sum of first n number of "<<n<<" is: "<<sumofn<<endl;

    int digsum= sumofdigits(n);
    int rvrsenum= reversenum(n);
    cout<<"dig sum of: "<<n<<" is: "<<digsum<<"& reverse is: "<<rvrsenum<<endl;

    cout<<"enter the power: ";
    if(!(cin>>p)) return 0;

    int power= powerbyrecursion(n,p);
    cout<<n<<" raised to the power "<<p<<" is: "<<power<<endl;

    return 0;
}