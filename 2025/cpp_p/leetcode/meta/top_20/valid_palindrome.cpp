// Problem: 125. Valid Palindrome
// Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) left++;
            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) right--;

            // Compare characters ignoring case
            if (tolower(s[left]) != tolower(s[right])) return false;

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Test case 1: valid palindrome with punctuation
    string s1 = "A man, a plan, a canal: Panama";
    cout << boolalpha << sol.isPalindrome(s1) << endl; // true

    // Test case 2: not a palindrome
    string s2 = "race a car";
    cout << boolalpha << sol.isPalindrome(s2) << endl; // false

    // Test case 3: empty string (considered a palindrome)
    string s3 = "";
    cout << boolalpha << sol.isPalindrome(s3) << endl; // true

    // Test case 4: alphanumeric palindrome
    string s4 = "0P";
    cout << boolalpha << sol.isPalindrome(s4) << endl; // false

    return 0;
}
