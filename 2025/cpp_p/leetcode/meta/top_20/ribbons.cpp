#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if we can get at least k ribbons of length x
bool canCut(const vector<int>& ribbons, int x, int k) {
    int count = 0;
    for (int ribbon : ribbons) {
        count += ribbon / x;
        if (count >= k) return true;  // Early exit if already sufficient
    }
    return count >= k;
}

// Function to find the maximum possible ribbon length
int maxRibbonLength(vector<int>& ribbons, int k) {
    int left = 1, right = *max_element(ribbons.begin(), ribbons.end());
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canCut(ribbons, mid, k)) {
            result = mid;  // Update the result
            left = mid + 1; // Try for a larger length
        } else {
            right = mid - 1; // Try for a smaller length
        }
    }

    return result;
}

// Main function to test the solution
int main() {
    vector<int> ribbons = {9, 7, 5}; // Example input
    int k = 3;
    cout << "Maximum Ribbon Length: " << maxRibbonLength(ribbons, k) << endl;
    // O(n log m), where n is the number of ribbons and m is the max ribbon length.

    return 0;
}
