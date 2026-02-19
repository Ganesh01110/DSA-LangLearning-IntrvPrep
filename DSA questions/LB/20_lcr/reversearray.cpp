#include<iostream>
#include<array>
using namespace std;

void Reverse_array(){
    int a[]={5,7,9,19,22,23};
    int n=6;

    for(int i=0,j=n-1;i<j;i++,j--){
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }

    cout<<"printing reverse arry"<<endl;
    for(int i:a){
       cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    Reverse_array();

    return 0;
}