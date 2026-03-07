#include <iostream>
#include <vector>
using namespace std;

/**
 * Sorting Algorithms (Revised)
 * Logic: Bubble Sort and Selection Sort implementations.
 */

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int n;
    cout << "Enter array size: "; cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> arr2 = arr;
    
    bubbleSort(arr);
    cout << "Bubble Sorted: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    selectionSort(arr2);
    cout << "Selection Sorted: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    
    return 0;
}
