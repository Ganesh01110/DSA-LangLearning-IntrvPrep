#include <iostream>
#include <climits>
using namespace std;

void printarr(int arr[] , int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    cout<<endl;
}

int maxsubarraysum(int arr[] , int n){
    int maxi= INT_MIN ; int sum=0 ;

    for(int i=0;i<n;i++){
        sum = sum+arr[i];

        if(sum>maxi)
          maxi=sum;

        if(sum<0)
          sum=0;  
    }

    return maxi;
}

int main(){
    int n;
    cout<<"enter size of array: " ;
    if(!(cin>>n)) return 0;

    int arr[n];
    
    cout<<"enter an array: ";
    for(int i=0;i<n ;i++ ) cin>>arr[i];

    printarr(arr , n);

    int result= maxsubarraysum(arr , n);
    cout<<"maximum subarray sum is: "<<result<<endl;

    return 0;
}