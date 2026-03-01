#include <iostream>
#include <vector>
using namespace std;

int input(){
    int i;
    cout<<"Enter the size of array: ";
    cin>>i;

    int arr[i] ;
    cout<<"Enter the elements of array: ";
    for(int j=0 ; j<i; j++){
        cin>>arr[j];
    }

    cout<<"The elements of array are: ";
    for(int k=0;k<i; k++){
        cout<<arr[k]<<" ";
    }

    return 0;
}

int maxmin(){
    int i;
    cout<<"Enter the size of array: ";
    cin>>i;

    int arr[i] ;
    cout<<"Enter the elements of array: ";
    for(int j=0 ; j<i; j++){
        cin>>arr[j];
    }

    cout<<"The min and max elements of array are: ";
    int max = arr[0];
    int min = arr[0];
    for(int k=0;k<i; k++){
        // cout<<arr[k]<<" ";
        if(max < arr[k])
         max = arr[k] ;

        if(min > arr[k])
         min = arr[k] ;
    }

    cout<< "max number is:"<< max << " & min number is:"<<min<< endl;

    return 0;
}

int linearsearch(){
    int i;
    cout<<"Enter the size of array: ";
    cin>>i;

    int arr[i] ;
    cout<<"Enter the elements of array: ";
    for(int j=0 ; j<i; j++){
        cin>>arr[j];
    }

    int e,p=-1;
    cout<<"enter element to be serched:";
    cin>>e;


    for(int k=0;k<i; k++){
        // cout<<arr[k]<<" ";
       if (arr[k] == e){
        p = k;
       }
    }
    if (p>=0) cout<<"Element found at index: "<<p<<endl;
    else cout<<"Element not found in array"<<endl;

    return 0;
}

int sum(){
    int i;
    cout<<"Enter the size of array: ";
    cin>>i;

    int arr[i] ;
    cout<<"Enter the elements of array: ";
    for(int j=0 ; j<i; j++){
        cin>>arr[j];
    }

    int sum=0;


    for(int k=0;k<i; k++){
        // cout<<arr[k]<<" ";
        sum= sum+ arr[k] ;
    }
    cout<<"sum of elements are: "<<sum<<endl;
    

    return 0;
}

int reverse(){
    int i;
    cout<<"Enter the size of array: ";
    cin>>i;

    int arr[i] ;
    cout<<"Enter the elements of array: ";
    for(int j=0 ; j<i; j++){
        cin>>arr[j];
    }

    int arr2[i];

    for(int k=i;k>=0; k--){
        // cout<<arr[k]<<" ";
        arr2[i-k-1] = arr[k] ;
    }
    cout<<"reverse of array is: ";
    for(int k=0;k<i; k++){
        cout<<arr2[k]<<" ";
    }
   
    return 0;
}

bool issorted(int arr[],int n){
   for(int k=0;k<n-1; k++){
        if(arr[k]>arr[k+1]) return false;
    }
    return true;
}

int reverse2p(){
    int i;
    cout<<"Enter the size of array: ";
    cin>>i;

    int arr[i] ;
    cout<<"Enter the elements of array: ";
    for(int j=0 ; j<i; j++){
        cin>>arr[j];
    }

    bool sorted = issorted(arr,i);
    if (sorted == true) cout<<"array is sorted in ascending order"<<endl;
    else cout<<"array is not sorted in ascending order"<<endl;

   int start =0;
   int end = i-1;
    while (start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    cout<<"reverse of array is: ";
    int max =arr[0], second=arr[0] ;
    for(int k=0; k<i; k++){
        cout<<arr[k]<<" ";
        if(arr[k] > max){
            second = max ;
            max=arr[k];
        }else if (arr[k] > second && arr[k] != max) {
            second = arr[k];
        } 
    }
    cout<<endl<<"largest: "<<max << " 2nd largest: "<<second<<endl;
   
    return 0;
}

void bubbleSort(int arr[], int n){
    for(int i=0 ; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

int binarysearch(){
    int i;
    cout<<"Enter the size of array: ";
    cin>>i;

    int arr[i] ;
    cout<<"Enter the elements of array: ";
    for(int j=0 ; j<i; j++){
        cin>>arr[j];
    }

    cout<<"The elements of array are: ";
    for(int k=0;k<i; k++){
        cout<<arr[k]<<" ";
    }

    bool sorted = issorted(arr,i);

    // binary searching process

    if (sorted == true){

        int e,p=-1;
    cout<<"enter element to be searched:";
    cin>>e;

    int start =0 , end= i-1;

    while(start<=end){
        int mid= (start+end)/2;
        if (arr[mid] ==e){
            p= mid;
            break;
        }else if(arr[mid]<e){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    if (p>=0) cout<<endl<<"Element:"<<e<<" found at index: "<<p<<endl;
    else cout<<"Element not found in array"<<endl;

    }else{
        cout<<endl<<"Array is not sorted in ascending order"<<endl;

        cout<<"sorting process started.."<<endl;

            // Step 1: Sort the array
        bubbleSort(arr, i);

        cout << "Sorted array: ";
        for(int k = 0; k < i; k++){
            cout << arr[k] << " ";
        }
    }

    

    return 0;
}

int correctbinarysearch(){
    int i;
    cout<<"Enter the size of array: ";
    cin>>i;

    int arr[i] ;
    cout<<"Enter the elements of array: ";
    for(int j=0 ; j<i; j++){
        cin>>arr[j];
    }

    cout<<"The elements of array are: ";
    for(int k=0;k<i; k++){
        cout<<arr[k]<<" ";
    }

    bool sorted = issorted(arr,i);

    // binary searching process

    if (!sorted){
        cout<<"\n array is not sorted"<<endl;
        bubbleSort(arr, i);
    }else{
        cout<<"\n Array is  sorted in ascending order"<<endl;

    }

     cout<<"The elements of sortedarray are: ";
    for(int k=0;k<i; k++){
        cout<<arr[k]<<" ";
    }

    // binary searching process

     int e,p=-1;
    cout<<"\n enter element to be searched:";
    cin>>e;

    int start =0 , end= i-1;

    while(start<=end){
        int mid= (start+end)/2;
        if (arr[mid] ==e){
            p= mid;
            break;
        }else if(arr[mid]<e){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    if (p>=-1) cout<<endl<<"Element:"<<e<<" found at index: "<<p<<endl;
    else cout<<"Element not found in array"<<endl;

    

    return 0;
}

int main(){
    // input();
    // maxmin();
    // linearsearch();
    // sum();
    // reverse();
    // reverse2p();
    // binarysearch();
    correctbinarysearch();
}
