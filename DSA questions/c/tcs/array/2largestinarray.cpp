#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findlargest(int arr[],int n) {
    int largest= arr[0];
    for(int i=0;i<n;i++){
        if (largest < arr[i]){
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int arr[] = {14,7,15,2,34};
    int n=5;
    std::cout<< "largest in array is:" << findlargest(arr,n);
}
