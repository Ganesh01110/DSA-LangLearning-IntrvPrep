// array basics and scope
#include<iostream>
using namespace std;


void printingIntarray(int arr[] , int size){
    
    for(int i=0 ;i<size;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"printing done of int array"<<endl;
}

void printingChararray(char arr[] , int size){
    
    for(int i=0 ;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n printing done of char array"<<endl;
}

void update(int arr[],int place,int num){
    cout<<"inside update function"<<endl;

    arr[place]= num;

    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i=0 ;i<size;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n update print complete,back to main function"<<endl;

}

void randomarray(){
    int arr1[10];
    int arr2[]={1,2,3};
    char arr3[]={'a','b','c','d','e','f','g','h','k'};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    

    printingIntarray(arr1 ,size1 );
    printingIntarray(arr2 ,size2 );
    printingChararray(arr3 ,size3 );
    
    update(arr2 , 1 , 120);
    printingIntarray(arr2 ,size2 );

    // for(int i=0 ;i<10;i++){
    //     cout<<arr1[i]<<endl;
    // }
    // cout<<"end of 1st loop"<<endl;
    // for(int i=0 ;i<size1;i++){
    //     cout<<arr2[i]<<endl;
    // }
    // cout<<"end of 2nd loop"<<endl;
    // for(int i=0 ;i<9;i++){
    //     cout<<arr3[i]<<" ";
    // }
}
int main(){
    randomarray();
   
    return 0;
}