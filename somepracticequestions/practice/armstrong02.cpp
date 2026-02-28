#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n){
    int digit =0;
    while(n>0){
        digit++;
        n=n/10;
    }
    cout<<"digit is:"<<digit<<endl;
    return digit;
}

int power(int base, int exp){
    int res = 1;
    for (int i=0; i<exp; i++){
        res= res*base;
    }
    return res;
}

bool isArmstrong(int n){
    if(n==0 || n==1) return true;

    int sum=0;
    int digit =countDigits(n);
    int temp = n;
    while(temp>0){
        sum = sum + power(temp%10, digit);
        temp = temp/10;
    }
    if(sum==n) return true;
    else return false;
}

int main (){
    int n;
    if (!(cin>>n)) return 0;
    
    if(isArmstrong(n)==true){
        cout<<"Armstrong Number"<<endl;
    }
    else{
        cout<<"Not Armstrong Number"<<endl;
   }
    return 0;
}