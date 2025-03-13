#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int maximumSwap(int num) {
    string numStr = to_string(num);
    int n = numStr.size();
    vector<int> lastIndex(10, -1);
    
    // Store the last occurrence of each digit
    for (int i = 0; i < n; i++) {
        lastIndex[numStr[i] - '0'] = i;
    }
    
    // Try to swap the first smaller digit with the largest possible digit
    for (int i = 0; i < n; i++) {
        for (int d = 9; d > numStr[i] - '0'; d--) {
            if (lastIndex[d] > i) {
                swap(numStr[i], numStr[lastIndex[d]]);
                return stoi(numStr);
            }
        }
    }
    return num;
}

int main() {
    // Example test cases
    cout << maximumSwap(2736) << endl;  // Output: 7236
    cout << maximumSwap(9973) << endl;  // Output: 9973
    cout << maximumSwap(98368) << endl; // Output: 98863
    return 0;
}
