#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Second Largest Element (Revised)
 * Logic: Single pass O(n) scan to find largest and second largest.
 */

int main() {
    int n;
    cout << "Enter array size: "; cin >> n;
    if (n < 2) {
        cout << "Array must have at least 2 elements." << endl;
        return 0;
    }
    
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int largest = INT_MIN, secondLargest = INT_MIN;
    for (int x : arr) {
        if (x > largest) {
            secondLargest = largest;
            largest = x;
        } else if (x > secondLargest && x != largest) {
            secondLargest = x;
        }
    }
    
    if (secondLargest == INT_MIN) cout << "No second largest element exists." << endl;
    else cout << "Second Largest: " << secondLargest << endl;
    
    return 0;
}
