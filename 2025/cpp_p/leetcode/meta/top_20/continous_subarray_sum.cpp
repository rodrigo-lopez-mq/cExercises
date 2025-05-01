// Problem: 523. Continuous Subarray Sum
// Given an integer array nums and an integer k, return true if there exists a continuous 
// subarray of size at least two that sums up to a multiple of k, or false otherwise.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumMap; // Map to store the remainder and its index
        prefixSumMap[0] = -1;  // Base case: remainder 0 at index -1
        
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            
            // Handle the case when k is not zero to avoid division by zero
            if (k != 0) {
                sum %= k;
            }
            
            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                // If we have seen this remainder before and the length of subarray is >= 2
                if (i - prefixSumMap[sum] > 1) {
                    return true;
                }
            } else {
                prefixSumMap[sum] = i;  // Store the first occurrence of this remainder
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Test case 1: Subarray sum is a multiple of k
    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;
    cout << boolalpha << sol.checkSubarraySum(nums1, k1) << endl; // Output: true

    // Test case 2: No valid subarray
    vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 13;
    cout << boolalpha << sol.checkSubarraySum(nums2, k2) << endl; // Output: false

    return 0;
}
