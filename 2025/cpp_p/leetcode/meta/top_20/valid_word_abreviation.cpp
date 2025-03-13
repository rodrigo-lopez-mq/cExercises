#include <iostream>
#include <string>

using namespace std;

bool validWordAbbreviation(string word, string abbr) {
    int i = 0, j = 0; // Pointers for word and abbreviation
    int n = word.size(), m = abbr.size();

    while (i < n && j < m) {
        if (isdigit(abbr[j])) { 
            if (abbr[j] == '0') return false; // Leading zeros are not allowed

            int num = 0;
            while (j < m && isdigit(abbr[j])) {
                num = num * 10 + (abbr[j] - '0');
                j++;
            }
            i += num; // Skip characters in word
        } 
        else {
            if (word[i] != abbr[j]) return false; // Character mismatch
            i++, j++;
        }
    }

    return i == n && j == m; // Ensure both pointers reach the end
}

// Main function to test the solution
int main() {
    cout << boolalpha; // Print 'true' or 'false' instead of 1 or 0
    cout << validWordAbbreviation("internationalization", "i12iz4n") << endl; // true
    cout << validWordAbbreviation("apple", "a2e") << endl; // false
    return 0;
}
