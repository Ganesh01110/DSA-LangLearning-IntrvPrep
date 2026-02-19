#include<iostream>
#include<stack>
using namespace std;

int main(){
stack<string> s;

s.push("ganesh");
s.push("sahu");
s.push("\\hello world\\");

cout<<"top element"<<s.top()<<endl;

s.pop();
cout<<"top element"<<s.top()<<endl;
cout<<"size of stack"<<s.size()<<endl;
cout<<"size of stack"<<s.empty()<<endl;


}