#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

string simplifyPath(string path) {
    stack<string> stk;
    stringstream ss(path);
    string token;
    
    // Split the path by '/' and process each part
    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            continue; // Ignore empty parts and '.'
        } else if (token == "..") {
            if (!stk.empty()) {
                stk.pop(); // Go up one directory
            }
        } else {
            stk.push(token); // Valid directory name
        }
    }
    
    // Construct the simplified path
    string result = "";
    while (!stk.empty()) {
        result = "/" + stk.top() + result;
        stk.pop();
    }
    
    return result.empty() ? "/" : result;
}

int main() {
    // Example test cases
    cout << simplifyPath("/home/") << endl;           // Output: "/home"
    cout << simplifyPath("/../") << endl;             // Output: "/"
    cout << simplifyPath("/home//foo/") << endl;     // Output: "/home/foo"
    cout << simplifyPath("/a/./b/../../c/") << endl; // Output: "/c"
    cout << simplifyPath("/a/../../b/../c//.//") << endl; // Output: "/c"
    return 0;
}
