#include <iostream>
using namespace std;

bool isPalindrome(string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // Try removing one character: either left or right
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;
}

// Main function to test the solution
int main() {
    cout << validPalindrome("aba") << endl;  // Expected: true
    cout << validPalindrome("abca") << endl; // Expected: true
    cout << validPalindrome("abc") << endl;  // Expected: false

    return 0;
}
