#include<iostream>
#include<list>

using namespace std;
int main(){
     list<int> l;

     l.push_back(1);
     l.push_front(2);

    cout<<"printing output"<<endl;
     for(int i:l){
        cout<<i<<" ";
     }
    cout<<endl;

    l.erase(l.begin());
    cout<<"printing output after erase"<<endl;
     for(int i:l){
        cout<<i<<" ";
     }
    cout<<endl;
    // pushback,pushfront,popback,popfront,size,begin,end->all aplicable
    list<int> n(l); 
    //for copying a list in another
    cout<<"printing output after copy:"<<endl;
     for(int i:n){
        cout<<i<<" ";
     }
    cout<<endl;

    
     n.push_back(5);
     
     n.push_front(8);
     cout<<"printing output after copy"<<endl;
     for(int i:n){
        cout<<i<<" ";
     }
    cout<<endl;

    list<int> k(5,11);//initiatializing with a specific value


    return 0;
}
