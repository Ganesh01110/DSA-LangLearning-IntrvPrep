#include <iostream>
#include <vector>
using namespace std;

/**
 * Bubble and Selection Sort
 * Time Complexity: O(N^2)
 */

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
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
    int n, type;
    if (!(cin >> n >> type)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    if (type == 1) bubbleSort(arr);
    else selectionSort(arr);
    
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    return 0;
}
