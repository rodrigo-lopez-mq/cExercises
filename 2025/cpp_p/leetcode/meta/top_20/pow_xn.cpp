// Problem: 50. Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (x^n).

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // Handle the case when n is negative
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double result = 1.0;
        while (n > 0) {
            if (n % 2 == 1) {  // If n is odd
                result *= x;
            }
            x *= x;  // Square the base
            n /= 2;  // Divide n by 2 (shift right)
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1: Positive exponent
    double x1 = 2.0;
    int n1 = 10;
    cout << sol.myPow(x1, n1) << endl; // Output: 1024

    // Test case 2: Negative exponent
    double x2 = 2.0;
    int n2 = -2;
    cout << sol.myPow(x2, n2) << endl; // Output: 0.25

    // Test case 3: Base 0
    double x3 = 0.0;
    int n3 = 5;
    cout << sol.myPow(x3, n3) << endl; // Output: 0

    // Test case 4: Exponent 0
    double x4 = 2.0;
    int n4 = 0;
    cout << sol.myPow(x4, n4) << endl; // Output: 1

    return 0;
}
