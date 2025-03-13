#include <iostream>
#include <stack>
using namespace std;

string minRemoveToMakeValid(string s) {
    stack<int> st;
    
    // Mark positions to remove
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty()) {
                st.pop();
            } else {
                s[i] = '*'; // Mark invalid ')'
            }
        }
    }
    
    // Mark remaining invalid '('
    while (!st.empty()) {
        s[st.top()] = '*';
        st.pop();
    }
    
    // Build the valid string
    string result;
    for (char c : s) {
        if (c != '*') result += c;
    }
    
    return result;
}

// Main function to test the solution
int main() {
    string s1 = "(a)b(c)d)";
    string s2 = "((a))())";
    string s3 = "a)b(c)d";

    cout << minRemoveToMakeValid(s1) << endl; // Expected: "(a)b(c)d"
    cout << minRemoveToMakeValid(s2) << endl; // Expected: "((a))()"
    cout << minRemoveToMakeValid(s3) << endl; // Expected: "ab(c)d"

    return 0;
}
