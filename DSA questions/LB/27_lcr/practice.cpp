#include<iostream>
using namespace std;

void funcpractice(int *p){
    cout<<"in function: *p: "<<*p<<endl;
    // p=p+1; //no change
    *p=*p+5; //change in i and *p
    //**p=**p+5;
    cout<<"after modification: *p: "<<*p<<endl;
    // p=p+1; // incrementing the pointer by 1, but the value of i remains unchanged.
}

void funcforpointer(){
   int i =5;
   int* p =&i;

   cout<<"before function call"<<endl;
   cout<<"i: "<<i<<" ,&i: "<< &i <<" ,p: "<<p<<" ,&p: "<<&p<<" ,*p: "<<*p <<endl;
   funcpractice(p);
   cout<<"after function call"<<endl;
   cout<<"i: "<<i<<" ,&i: "<< &i<<" ,p: "<<p<<" ,&p: "<<&p<<" ,*p: "<<*p <<endl;

}

int main(){
    /*
    int i=5;
    int* p=&i;
    int** k= &p;
    cout<<"\ndetails about i: "<<"content= i= "<<i<<" ,address= &i: "<<&i<<endl;
    cout<<"\ndetails about p(pointer): "<<"content= p= "<<p<<" ,address= &p: "<<&p<<" ,value in p= *p : "<< *p <<endl;
    cout<<"\ndetails about k(double pointer): "<<"content= k= "<<k<<" ,address= &k: "<<&k<<" ,value in k= *k : "<< *k<<", **k : "<< **k  <<endl; 
        
    cout<<"\nso :"<<"i = *p= **K = "<<i<<" = "<< *p<<" = "<<**k<<endl;
    cout<<"so :"<<"&i = p = *K = "<<&i<<" = "<< p<<" = "<<*k<<endl;
    cout<<"so :"<<"&p = K = "<<&p<<" = "<< k<<endl;

    */

   funcforpointer();

}