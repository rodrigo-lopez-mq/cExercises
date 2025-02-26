#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // Compare mid with its neighbors
        if (nums[mid] > nums[mid + 1]) {
            // We are on a descending part, so the peak is on the left
            right = mid;
        } else {
            // We are on an ascending part, so the peak is on the right
            left = mid + 1;
        }
    }
    
    // After the loop, left == right, and it's the peak element
    return left;
}

int main() {
    // Test cases
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    
    cout << "Peak index in nums1: " << findPeakElement(nums1) << endl;  // Output: 2
    cout << "Peak index in nums2: " << findPeakElement(nums2) << endl;  // Output: 5 or 1
    
    return 0;
}
