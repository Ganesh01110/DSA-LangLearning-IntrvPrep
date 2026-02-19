#include<iostream>
using namespace std;

int binaryserch(int arr[],int size,int key){
    int end=size-1;
    int start=0;
    int mid = (start+end) /2;
    while(start<=end){
        

        if(arr[mid]==key){
            return  mid;
            // cout<<"\nelement :"<< key<<"found at:"<<mid<<endl;
        }
        
        if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }

        mid = (start+end ) /2;
    }


    return -1;
}

int main(){
    int odd[7]={1,2,3,4,5,6,7};
    int even[8]={11,12,13,14,15,16,17,18};
    int size=sizeof(odd)/sizeof(odd[0]);
    int key=6;

    int result = binaryserch(odd,size,key);

    if(result==-1){
        cout<<"element doesnt exist in array"<<endl;
    }else{
        cout<<"\nelement: "<< key << " found at:"<<result<<endl;
    }
    
    return 0;

}