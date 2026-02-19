#include<iostream>

 using namespace std;

 void withoutConditionloop(){
    int n=5;
    int i =1;
    for ( ; ; ){
        if (i<=n){
            cout<<i<<endl;
        }else{
            break;
        }
        i++;
    }
 }

 void multipleconditionloop(){
    for (int a=0,b=1; a<=10 && b<=11;a++,++b){
        cout<<a<<" "<<b<<endl;
    }
 }

 void palindromwithshift(){
    cout<<"palindrom"<<endl;
    int a =0;
    int b= 1;
    int n= 8;
    int sum=0;
    for(int j=0;j<=n;j++){
        sum=a+b;
        a=b;
        b=sum;
        cout<<sum <<" ";
    }
 }

 void primenum(){
    cout<< endl;
    int n=30;
    for (int i=2;i<n;i++){
        if (n%i==0){
            cout<< n << ": is not a prime number"<<endl;
            break;
        }
    }
 }

 void continueKeyword(){
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<"hii"<<endl;
        cout<<"heyy"<<endl;
        continue;

        cout<<"reply"<<endl;
    }
 }

 int main(){
    int a =4;
    int b=6;
    cout<< "a&b"<< (a&b)<<endl;
    cout<< "a|b"<< (a|b)<<endl;
    cout<< "a^b"<< (a^b)<<endl;
    cout<< "~a"<< (~a)<<endl;

    // left shift operator << it applies maximum time but not always,sometimes it creates a negative number.
    // >> right shift operator make shifts the bit of any number to right , other way to imagine it are x/2 if applied onece on x and x/(2*2) if applied 2 times on x
    // for +ve it started with zero but for -ve it is compiler dependent.

    cout<<(17>>1)<<endl;
    cout<<(17>>2)<<endl;
    cout<<(17<<1)<<endl;
    cout<<(17<<2)<<endl;

    // i++ post increment
    // ++i pre increment
    // --i pre decrement
    // i-- post decrement
    int c=a++;
    int d=a;
    ++a;
    int e=a++;
    cout << c <<"\n";
    cout << d <<"\n";
    cout << e <<"\n";
    cout << a <<"\n";

    int f=b--;
    int g=b;
    --b;
    int h=b--;
    cout << f <<"\n";
    cout << g <<"\n";
    cout << h <<"\n";
    cout << b <<"\n";


    withoutConditionloop();
    multipleconditionloop();
    palindromwithshift();
    primenum();
    continueKeyword();

    return 0;
 }