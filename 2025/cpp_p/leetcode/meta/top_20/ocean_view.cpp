#include <iostream>
#include <vector>
using namespace std;

vector<int> findBuildings(vector<int>& heights) {
    vector<int> result;
    int maxHeight = 0; // Track the maximum height from the right

    // Traverse from right to left
    for (int i = heights.size() - 1; i >= 0; --i) {
        if (heights[i] > maxHeight) {
            result.push_back(i); // This building has an ocean view
            maxHeight = heights[i]; // Update max height
        }
    }

    // Reverse to maintain increasing order
    reverse(result.begin(), result.end());
    return result;
}

// Main function to test the solution
int main() {
    vector<int> heights1 = {4, 2, 3, 1};
    vector<int> heights2 = {4, 3, 2, 1};
    vector<int> heights3 = {1, 3, 2, 4};

    vector<int> res1 = findBuildings(heights1);
    vector<int> res2 = findBuildings(heights2);
    vector<int> res3 = findBuildings(heights3);

    for (int idx : res1) cout << idx << " ";
    cout << endl;

    for (int idx : res2) cout << idx << " ";
    cout << endl;

    for (int idx : res3) cout << idx << " ";
    cout << endl;

    return 0;
}
