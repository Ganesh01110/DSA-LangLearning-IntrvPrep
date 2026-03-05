#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Matrix Rotation (90 Degrees Clockwise)
 * Strategy:
 * 1. Transpose the matrix (swap mat[i][j] with mat[j][i]).
 * 2. Reverse each row.
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 */

void rotate90(vector<vector<int>>& mat) {
    int n = mat.size();
    
    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    // Reverse Rows
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    }
    
    rotate90(mat);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << (j == n-1 ? "" : " ");
        cout << endl;
    }
    
    return 0;
}
