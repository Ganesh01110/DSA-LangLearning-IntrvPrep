// given an array and an integer k. we need to  find the maximum element in each of the contiguous aubarrays.
// input:247163
// k:3
// op:7776 i.e for 1st 3 from array (247)=>max=7 (471)=>max=7 (716)=>max=7 so on..


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve(vector<int>& arr, int k) {
    vector<int> ans;
    for (int i = 0; i < arr.size() - k + 1; i++) {
        priority_queue<int> maxHeap;
        for (int j = i; j < i + k; j++) {
            maxHeap.push(arr[j]);
        }
        ans.push_back(maxHeap.top());
    }
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
}

void optimalSolution(vector<int>& arr, int k) {
    priority_queue<pair<int, int>> maxHeap;
    vector<int> ans;

    for (int i = 0; i < k; i++) {
        maxHeap.push({arr[i], i});
    }
    ans.push_back(maxHeap.top().first);

    for (int i = k; i < arr.size(); i++) {
        maxHeap.push({arr[i], i});
        while (maxHeap.top().second <= i - k) {
            maxHeap.pop();
        }
        ans.push_back(maxHeap.top().first);
    }
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);
        if (cin.get() == '\n') break;
    }
    int k;
    cin >> k;
    solve(arr, k);
    optimalSolution(arr, k);
    return 0;
}