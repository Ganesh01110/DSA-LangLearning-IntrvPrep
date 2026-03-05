#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/**
 * Fractional Knapsack Problem (Greedy)
 * Time Complexity: O(N log N)
 */

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    
    double finalValue = 0.0;
    for (auto it : items) {
        if (it.weight <= W) {
            W -= it.weight;
            finalValue += it.value;
        } else {
            finalValue += it.value * ((double)W / it.weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) cin >> items[i].value >> items[i].weight;
    
    cout << fixed << setprecision(2) << fractionalKnapsack(W, items) << endl;
    return 0;
}
