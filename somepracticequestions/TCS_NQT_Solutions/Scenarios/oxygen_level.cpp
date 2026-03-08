#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * SCENARIO: Oxygen Level Monitoring
 * PROBLEM: 3 trainees are evaluated for 3 rounds. Average oxygen level of each trainee
 * is calculated. If any trainee's average is below 70, they are unfit.
 * Output the trainee(s) with max average.
 * 
 * CORE PATTERN: 2D Matrix (Trainee x Round)
 * COMPLEXITY: O(9) - Fixed size in NQT typically.
 */

int main() {
    vector<vector<int>> oxygen(3, vector<int>(3));
    vector<int> avg(3, 0);
    
    for (int i = 0; i < 9; i++) {
        int val; cin >> val;
        // Check for valid range [1, 100] as per typical NQT
        if (val < 1 || val > 100) oxygen[i % 3][i / 3] = 0; 
        else oxygen[i % 3][i / 3] = val; // i%3 = trainee, i/3 = round
    }
    
    int maxAvg = 0;
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) sum += oxygen[i][j];
        avg[i] = sum / 3;
        maxAvg = max(maxAvg, avg[i]);
    }
    
    if (maxAvg < 70) {
        cout << "All trainees are unfit" << endl;
    } else {
        for (int i = 0; i < 3; i++) {
            if (avg[i] == maxAvg) cout << "Trainee Number: " << (i + 1) << endl;
        }
    }
    
    return 0;
}
