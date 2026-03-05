#include <iostream>
#include <string>
#include <stack>
using namespace std;

/**
 * Balanced Parenthesis Check
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') || 
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    if (!(cin >> s)) return 0;
    
    if (isBalanced(s)) cout << "Balanced" << endl;
    else cout << "Not Balanced" << endl;
    
    return 0;
}
