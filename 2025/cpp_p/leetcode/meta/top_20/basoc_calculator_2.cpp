#include <iostream>
#include <stack>
using namespace std;

/*
Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/

int calculate(string s) {
    stack<int> stk;
    int num = 0;
    char op = '+'; // Start with a '+' operator to handle first number correctly

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Build the number
        }

        // If we encounter an operator or reach the end of the string, process the operation
        if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
            if (op == '+') {
                stk.push(num);
            } else if (op == '-') {
                stk.push(-num);
            } else if (op == '*') {
                int top = stk.top();
                stk.pop();
                stk.push(top * num);
            } else if (op == '/') {
                int top = stk.top();
                stk.pop();
                stk.push(top / num);
            }
            op = c; // Update operator
            num = 0; // Reset number
        }
    }

    // Compute final result
    int result = 0;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }

    return result;
}

// Main function to test the solution
int main() {
    string s1 = "3+2*2";
    string s2 = " 3/2 ";
    string s3 = " 3+5 / 2 ";

    cout << calculate(s1) << endl; // Expected: 7
    cout << calculate(s2) << endl; // Expected: 1
    cout << calculate(s3) << endl; // Expected: 5

    return 0;
}
