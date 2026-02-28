#include<iostream>
using namespace std;

int reverse(int n){
    int op=n;
    int rev=0;
    while(op>0){
        int rem = (op%10);
        rev = rev*10 + rem ;
        op = op/10;
    }

    cout<<"reverse is:"<<rev<<endl;
    return rev;
}

bool palindromcheck(int n){
    int original = n;
    int reversed = reverse(n);
    
    if(original == reversed) return true;
    else return false;

}

int main(){
    int n;
    cout<<"enter a number to check plaindrom or not:";
    if(!(cin>>n)) return 0;

    if(palindromcheck(n)) cout<< n <<" is a palindrom number." << endl;
    else cout<< n <<" is not a palindrom number." << endl;

    return 0;
}