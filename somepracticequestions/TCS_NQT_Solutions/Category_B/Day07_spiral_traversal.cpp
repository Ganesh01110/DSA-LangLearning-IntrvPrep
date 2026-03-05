#include <iostream>
#include <vector>
using namespace std;

/**
 * Spiral Matrix Traversal
 * Time Complexity: O(N*M)
 * Space Complexity: O(1)
 */

int main() {
    int r, c;
    if (!(cin >> r >> c)) return 0;
    
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> mat[i][j];
        
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) cout << mat[top][i] << " ";
        top++;
        
        for (int i = top; i <= bottom; i++) cout << mat[i][right] << " ";
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--) cout << mat[bottom][i] << " ";
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) cout << mat[i][left] << " ";
            left++;
        }
    }
    cout << endl;
    
    return 0;
}
