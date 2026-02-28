#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number :";
    if(!(cin>>n)) return 0;
    // factorial logic
    if (n<0){
        cout<<"factorial of negative number is not defined."<<endl;
        return 0;
    }
    if(n<=1){
        cout<<"factorial of "<< n <<" is 1."<<endl;
        return 0;
    }
    long long fact=1;
    for(int i=2 ; i<= n ; i++){
       fact = fact*i ;
    }
    cout<<"factorial of "<< n <<" is "<< fact <<"."<<endl;
    return 0;

}