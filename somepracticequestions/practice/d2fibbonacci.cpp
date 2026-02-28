#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number for fibbonacci series:";
    if(!(cin>>n)) return 0;
    if (n<=0) cout<<" for number:"<< n <<" no series is possible"<< endl;
    for (int i=0;i<=n ; i++){
        if(i==0) cout<< 0 <<" ";
        else if(i==1) cout<< 1 <<" " ;
        else{
            int a =0 , b=1 , c;
            for(int j=2 ; j<=i ; j++){
                c = a+b;
                a=b;
                b=c;
            }
            cout<< c <<" ";
        }

    }
    return 0;

}