// Problem: 1570. Dot Product of Two Sparse Vectors
// Given two sparse vectors, compute their dot product.
// Implement class SparseVector with the following methods:
// - SparseVector(vector<int> &nums) initializes the object with the vector.
// - int dotProduct(SparseVector& vec) returns the dot product of the two sparse vectors.

#include <iostream>
#include <vector>
using namespace std;

class SparseVector {
    // Store only non-zero elements as index-value pairs
    vector<pair<int, int>> data;

public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                data.emplace_back(i, nums[i]);
            }
        }
    }

    // Return the dot product of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        int i = 0, j = 0;

        // Two-pointer approach on both sparse lists
        while (i < data.size() && j < vec.data.size()) {
            if (data[i].first == vec.data[j].first) {
                result += data[i].second * vec.data[j].second;
                ++i;
                ++j;
            } else if (data[i].first < vec.data[j].first) {
                ++i;
            } else {
                ++j;
            }
        }

        return result;
    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {1, 0, 0, 2, 3};
    vector<int> nums2 = {0, 3, 0, 4, 0};

    SparseVector v1(nums1);
    SparseVector v2(nums2);

    cout << v1.dotProduct(v2) << endl; // Output: 8 (2*4)

    // Test case 2
    vector<int> nums3 = {0, 1, 0, 0, 2, 0, 0};
    vector<int> nums4 = {1, 0, 0, 0, 3, 0, 4};

    SparseVector v3(nums3);
    SparseVector v4(nums4);

    cout << v3.dotProduct(v4) << endl; // Output: 6 (2*3)

    return 0;
}
