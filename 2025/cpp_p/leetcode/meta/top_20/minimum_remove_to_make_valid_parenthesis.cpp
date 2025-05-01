// Problem: 1249. Minimum Remove to Make Valid Parentheses
// Given a string s of '(' , ')' and lowercase English characters,
// remove the minimum number of parentheses to make the input string valid.
// Return the resulting string.

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk; // Store indices of '('
        string result = s;

        // First pass: mark unmatched ')'
        for (int i = 0; i < result.size(); ++i) {
            if (result[i] == '(') {
                stk.push(i);
            } else if (result[i] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    result[i] = '*'; // mark for removal
                }
            }
        }

        // Second pass: mark unmatched '('
        while (!stk.empty()) {
            result[stk.top()] = '*';
            stk.pop();
        }

        // Build final result without marked characters
        string finalStr;
        for (char c : result) {
            if (c != '*') {
                finalStr += c;
            }
        }

        return finalStr;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "lee(t(c)o)de)";
    cout << sol.minRemoveToMakeValid(s1) << endl; // Output: "lee(t(c)o)de"

    // Test case 2
    string s2 = "a)b(c)d";
    cout << sol.minRemoveToMakeValid(s2) << endl; // Output: "ab(c)d"

    // Test case 3
    string s3 = "))((";
    cout << sol.minRemoveToMakeValid(s3) << endl; // Output: ""

    return 0;
}
