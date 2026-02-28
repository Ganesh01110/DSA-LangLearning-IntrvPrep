#include<iostream>
using namespace std;

int power(int base, int exp){
    int res=1;
   for(int i=1 ; i<=exp ; i++){
     res *= base;
   }
  //    cout<<"power is :"<< res <<endl;
    return res;
}

int main(){
    int n, a , r, apsum=0, gpsum=0 ,d;
    cout<<"enter first term (a):";cin>>a;
    cout<<"enter common difference (d) for AP:";cin>>d;
    cout<<"enter common ratio (r) for GP:";cin>>r;
    cout<<"enter number of terms (n):";cin>>n;

    cout<<"AP series is :";
    for(int i=0 ; i<n ; i++){
       int term= a + i*d;
       cout<< term <<" ";
       apsum += term; 
    }
    cout<<"\nsum of AP is :"<<apsum<<endl;

    // gp series
    cout<<"GP series is :";
    for(int i=0; i<=n-1; i++){
        int term = a*power(r,i);
        cout<< term <<" ";
    }
    cout<<endl<<"sum of gp is:";
    gpsum= (a*(power(r,n)-1)/(r-1));
    cout<<gpsum<<endl;
    

}