#include<iostream>
#include <climits>
using namespace std;

int linearserch(int arr[],int size,int num){
  
//   int size= sizeof(arr)/sizeof(arr[0]);
  for(int i=0 ; i<size ; i++){
    if(arr[i] == num){

        cout<<"match found for:"<<num<<" in array."<<endl;
        return i;

    }
  }
  return -1;
}

int getMax(int arr[],int size) {
    int maximum= INT_MIN ;
    for(int i=0 ; i<size ; i++){
      if( maximum<arr[i]){
        maximum = arr[i];
      }
  }
    cout<<"maximumm in this array is:"<<maximum<<endl;
    return maximum;
}

int getMin(int arr[],int size) {
    int minimum= INT_MAX ;
    for(int i=0 ; i<size ; i++){
      if( minimum>arr[i]){
        minimum = arr[i];
      }
}   
    cout<<"minimumm in this array is:"<<minimum<<endl;
    return minimum;
}

void printingIntarray(int arr[] , int size){
    
    for(int i=0 ;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nprinting done of int array"<<endl;
}

void reverseofarry(int arr[],int size){
     int start = 0;
    int end = size-1;

    while(start<=end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    printingIntarray(arr,size);
}

int main(){
    int arr[]={1,2,22,34,8,5,54,76,89,90};
    int number=89;
    int size= sizeof(arr)/sizeof(arr[0]);
    int result=linearserch(arr,size,number);
    if(result!= -1){
        cout<<"result at index of:"<< result << "in array"<<endl;
    }else{
        cout<<"no match"<<endl;
    }

    getMax(arr,size);
    getMin(arr,size);

    reverseofarry(arr,size);

    return 0;
}