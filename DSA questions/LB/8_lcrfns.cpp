#include<iostream>
using namespace std;

int power(int a , int b) {
    int ans=1;
    for (int i=0;i<b;i++){
        ans = ans * a;
    }
    return ans;
}
bool iseven(int n){
    if(n&1) { //odd condition
        return 0;
    }
    return 1; //0->odd,1->even
}

int evenorodd(int n){
    int r=iseven(n);
    cout<< " result of is even is : "<< r <<endl;
    if(n%2==0) {
        cout<< " it is a even number"<<endl;
        }
    else {
        cout<< " it is a odd number"<<endl;
        }
    return 0;
}



int primecheck(int n){
    int c=0;
  for(int i=2;i<n;i++){
      if(n%i==0)
       c +=1;
  }
  if(c>0){
    cout<<"it is not a prime number"<<endl;
  }else{
    cout<<"it is  a prime number"<<endl;
  }
  return 0;
}

int factorial(int f){
    int ans=1;
   if(f==0 || f==1){
      return 1;
   }
   else{
    for(int i=1;i<=f;i++){
     ans=ans*i;
    }
    return ans;
   }
 
}
int ncr(int n,int r){
    int result=factorial(n)/(factorial(r)*factorial(n-r));
    cout<<"result of ncr ;"<< result << endl;
    return 0;
}

int main() {

   cout<< "5 to the power 2 is: " << power(5 , 2) << endl;
   evenorodd(10);
   primecheck(13);
   cout<< "factorial of 4 is: " <<factorial(4)<<endl;
   ncr(5,2);
   return 0;    
}