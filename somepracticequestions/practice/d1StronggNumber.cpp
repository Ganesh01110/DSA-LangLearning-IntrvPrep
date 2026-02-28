#include <iostream>
using namespace std;

int factorial(int n){
    long long fact = 1;
    for(int i=2;i<=n;i++){
        fact *= i;
    }

    return fact;
}

bool isStrong(int n){
    if(n<=0) return false;
    int temp =n;
    long long sum=0;
    while(temp >0){
        sum += factorial(temp % 10);
        temp = temp/10;
    }
    if (sum == n ) return true;
    else return false;
   
}

int main(){
    int n;
    cout<<"enter a number: ";
    if(!(cin>>n)) return 0;

    if(isStrong(n)) cout<< n <<" number is strong number." << endl;
    else cout<< n <<" number is not a strong number." << endl;

    return 0;
}