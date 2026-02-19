#include<iostream>
using namespace std;

void experimentwitharrayforpointer(){

    int arr[5]={1,2,3,4,5};
    int *ptr=arr;
    cout<<"1st position of array indexes:"<<arr<<endl;

    cout<<"Array elements through pointer:\n";
    for(int i=0;i<5;i++){
        // cout<<"position of array indexes:"<<arr+sizeof(arr[0])<<endl;
        cout<<*ptr++<<" ";
        cout<<"\naddress of memory block of "<<i<<" of array is:"<<&arr[i]<<endl;
        cout<<"by *arr:"<<*arr << endl;
        // cout<<"by &arr[i]:"<<&arr[i]<<endl;
        // cout<<"by ptr+i:"<<ptr+i<<endl;
        // cout<<"by arr+i*sizeof(arr[0]):"<<arr+i*sizeof(arr[0])<<endl; unneccesary
        cout<<"-----------------------------\n";
    }

    // arr[i] = *(arr+i)
    // i[arr]=*(i+arr)
    int i=3;
    cout<<i[arr]<<endl;

    int temp[10] = {1,4};
    cout<<sizeof(temp)<<endl;
    cout<<"1st"<<sizeof(*temp)<<endl;
    cout<<"2nd"<<sizeof(&temp)<<endl;
    cout<<"3rd: "<<temp<<" : "<<&temp[0]<<" : "<<&temp<<" : "<<*temp<<endl;

    int *p = &temp[0];
    cout<<sizeof(p)<<endl;
    cout<<sizeof(*p)<<endl;
    cout<<sizeof(&p)<<endl;
    cout<<"4th : "<<p<<" : "<<&p<<" : "<<*p<<endl;

/*
    int arr[10];

//ERROR
   //arr = arr+1;

    int *ptr = &arr[0];
    cout << ptr << endl;
    ptr = ptr + 1;
    cout << ptr << endl;

    */
}

int main(){
    experimentwitharrayforpointer();

    return 0;
}