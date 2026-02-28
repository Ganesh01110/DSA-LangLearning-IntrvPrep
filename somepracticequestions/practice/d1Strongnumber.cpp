#include <iostream>

using namespace std;

bool strongnumber(int n){
    if (n<=0 ) return false;
   if (n==1 || n==0 ) return true;
    int temp =n;
    int sum = 0;

   while (temp>0){
        int digit = temp%10;
        int fact = 1;
        for (int i=2; i<=digit; i++){
            fact = fact*i;
        }
        sum = sum + fact;
        temp = temp/10;
   }
   if (sum == n) return true;
   else return false;
}

int main(){

    int n;
    cout<<"enter a number:";
    if(!(cin>>n)) return 0;

    if (strongnumber(n)) cout<< n << ": is a dtrong number" << endl;
    else cout<< n<< ": is not a strong number"<<endl;
    return 0;

}