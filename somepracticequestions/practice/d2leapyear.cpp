#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a year to check if its leap year or not:";
    if(!(cin>>n)) return 0;

    if((n%4 ==0 && n%100!=0 ) ||  n%400==0 ){
        cout<< n <<":year is a leap year."<<endl;
    }else cout<< n <<":year is not a leap year."<<endl;

    return 0;
}
