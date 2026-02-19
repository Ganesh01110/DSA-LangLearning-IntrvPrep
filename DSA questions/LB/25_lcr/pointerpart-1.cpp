#include <iostream>

using namespace std;

int main()
{
    int num = 5;
    /*
        int *ptr=&num;
            // &-> address operator.
        cout<<"value of num ="<< num <<endl;
        cout<<"value of *ptr ="<< *ptr<<endl;
        cout<<"value of ptr="<< ptr<<endl;

        int *p=0;
        p=&num;
        cout<<"value of *p ="<< *p <<endl;
        cout<<"value of p ="<< p <<endl;

        num++;
        cout<<"value of *ptr after increment="<< *ptr <<endl;
     */

    int q = num;
    q++;
    cout << "value of num after increment=" << num << endl;
    cout << "value of q after increment=" << q << endl;

    int *pointer = &num;
    (*pointer)++;
    cout << "value of num after increment=" << num << endl;
    cout << "value of *pointer after increment=" << *pointer << endl;
    cout << "value of pointer after increment=" << pointer << endl;

cout << "--------"<<endl;
    for(int i=0;i<5;i++){
        (*pointer)=(*pointer) *5;
      cout << "value of (*pointer) in a loop of multiplication at i=" <<i<< " is : " <<(*pointer) << endl;  
    }

    // copying a pointer
    int *l = pointer;
    l++;
    cout << "value of pointer after increment from l=" << pointer << endl;
    cout << "value of *pointer after increment from l=" << *pointer << endl;


// important

int k=3;
int *g=&k;
// cout<<(*t)++<<endl;
*g = *g+1;

cout<<k<<endl; // 4
cout<<*g<<endl; // 4

int *h=g;
*g =*g + 1;
cout<<"before *g: "<< *g <<endl;
cout<<"before g: "<< g <<endl;
g =g + 1;//it goes to next location , nad do not change actual value.
cout<<"after g: "<< g <<endl;




    return 0;
}