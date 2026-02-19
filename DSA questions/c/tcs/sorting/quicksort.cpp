// Given an array of n integers, sort the array using the Quicksort method.

// Example 1:
// Input:  N = 5  , Arr[] = {4,1,7,9,3}
// Output: 1 3 4 7 9 

// Explanation: After sorting the array becomes 1, 3, 4, 7, 9

// Intuition:

// Quick Sort is a divide-and-conquer algorithm like the Merge Sort. But unlike Merge sort, this algorithm does not use any extra array for sorting(though it uses an auxiliary stack space). So, from that perspective, Quick sort is slightly better than Merge sort.

// This algorithm is basically a repetition of two simple steps that are the following:

// Pick a pivot and place it in its correct place in the sorted array.
// Shift smaller elements(i.e. Smaller than the pivot) on the left of the pivot and larger ones to the right.

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

// Output:
// Before Using quick Sort:
// 4 6 2 5 7 9 1 3
// After Using quick sort:
// 1 2 3 4 5 6 7 9 

// Time Complexity: O(N*logN), where N = size of the array.


// Worst Case – This case occurs when the pivot is the greatest or smallest element of the array. If the partition is done and the last element is the pivot, then the worst case would be either in the increasing order of the array or in the decreasing order of the array. 

// Recurrence:
// F(n) = F(0)+F(n-1)  or  F(n) = F(n-1) + F(0) 

// Worst Case Time complexity: O(n2) 