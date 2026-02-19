#include<iostream>
#include<queue>
using namespace std;

int main(){
queue<string> q;
// fifo -> rule being followed
q.push("ganesh");
q.push("sahu");
q.push("\\hello world\\");

cout<<"front element :"<<q.front()<<endl;
cout<<"front element :"<<q.back()<<endl;
q.pop();
cout<<"front element :"<<q.front()<<endl;
cout<<"size after pop :"<<q.size()<<endl;


}