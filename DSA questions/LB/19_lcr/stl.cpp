#include<iostream>
#include<array>
#include<vector>
#include<deque>

using namespace std;

void basicArray(){
    int basic[]={1,2,3,4};
    int size=sizeof(basic)/sizeof(basic[0]);
    for(int i=0;i<size;i++ ){
        cout<<basic[i]<<" " ;
    }
    cout<<endl;
}
void Arraystl(){
    cout<<"------basics about stl funtion start------"<<endl;
    array<int , 5> a={1,2,3,4};

    int size=a.size();
    for(int i=0;i<size;i++ ){
        cout<<a[i]<<" " ;
    }
    cout<<endl;
    cout<<"element at 2nd index"<<a.at(2)<<endl;
    cout<<"empty or not->"<<a.empty()<<endl;
    cout<<"front element :"<<a.front()<<endl;
    cout<<"back element :"<<a.back()<<endl;
}
void Arrayvector(){ 
    cout<<"------array vector funtion start------"<<endl;
    vector<int> v;
    vector<int> a(5,1);
    // if size is known previously and want to initialize every place with a specific number (here 1);

    vector<int> last(a);
    cout<<"inside vector a :"<<endl;
    for(int i:a){
        cout<<i<<" " ;
    }
    cout<<endl;

    cout<<"inside vector last :"<<endl;
    for(int i:last){
        cout<<i<<" " ;
    }
    cout<<endl;

    cout<< v.size()<<endl;
    cout<< v.capacity()<<endl;

    v.push_back(1);
    cout<<"cap->"<<v.capacity()<<endl;

    v.push_back(5);
    cout<<"cap->"<<v.capacity()<<endl;
    
    v.push_back(3);
    cout<<"cap->"<<v.capacity()<<endl;
    cout<< "size->"<<v.size()<<endl;
    
    cout<<"front element :"<<v.front()<<endl;
    cout<<"back element :"<<v.back()<<endl;

    cout<<"before pop:"<<endl;
    for(int i:v){
        cout<<i<<" " ;
    }
    cout<<endl;
    v.pop_back();
    cout<<"after pop:"<<endl;
    for(int i:v){
        cout<<i<<" " ;
    }

    // clear function makes size null not capacity
    cout<<"size before clear:"<<v.size()<<endl;
    cout<<"cap before cler->"<<v.capacity()<<endl;
    v.clear();
    
    cout<<"cap after cler->"<<v.capacity()<<endl;
    cout<<"size after clear:"<<v.size()<<endl;

}

void doublyqueue(){
    cout<<"------double queue funtion start------"<<endl;
    // it is not a contiguous array structure like array
    // insertuon and deletion at both end
    // random access possible by .at and dynamic  #include<deque>
   deque<int> d = {3,2,5,7};
   d.pop_front();
   cout<<"first index element:"<<d.at(1)<<endl;
   d.push_back(1);
   d.push_front(5);
   cout<<"inside deq d :"<<endl;
    for(int i:d){
        cout<<i<<" " ;
    }
    cout<<endl;
    d.pop_back();
    for(int i:d){
        cout<<i<<" " ;
    }
    cout<<endl;
    
    cout<<"front element :"<<d.front()<<endl;
    cout<<"back element :"<<d.back()<<endl;
    cout<<"empty or not :"<<d.empty()<<endl;

    d.erase(d.begin(),d.begin()+1);//erase work in range
    cout<<"size after erase:"<<d.size()<<endl;
    for(int i:d){
        cout<<i<<" " ;
    }

    cout<<endl;
    // cout<<"cap->"<<d.capacity()<<endl; caapacity function doesnt work
    // cout<<"begin function:"<<d.begin()<<endl;

d.erase(d.end()-1,d.end());//erase work in range 0(n)
    cout<<"size after erase from end:"<<d.size()<<endl;
    for(int i:d){
        cout<<i<<" " ;
    }
    cout<<endl; 
      
    //   begin,end,front,back,at -> 0(1)

}

int main(){
    basicArray();
    Arraystl();
    Arrayvector();
    doublyqueue();

    return 0;
}