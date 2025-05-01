// Problem: 88. Merge Sorted Array
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums2 into nums1 as one sorted array in-place. nums1 has a size of m + n,
// where the last n elements are set to 0 and should be ignored initially.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start filling nums1 from the end
        int i = m - 1;           // Last element in nums1's actual data
        int j = n - 1;           // Last element in nums2
        int k = m + n - 1;       // Last position in nums1

        // Merge from the back to avoid overwriting elements in nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If any elements remain in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    sol.merge(nums1, m, nums2, n);
    for (int num : nums1) cout << num << " ";
    cout << endl;

    // Test case 2
    vector<int> nums1b = {1, 4, 5, 0, 0};
    vector<int> nums2b = {2, 3};
    m = 3, n = 2;
    sol.merge(nums1b, m, nums2b, n);
    for (int num : nums1b) cout << num << " ";
    cout << endl;

    return 0;
}
