#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right]; // Choose the last element as pivot
    int i = left; // Pointer for smaller elements

    for (int j = left; j < right; ++j) {
        if (nums[j] >= pivot) { // Sorting in descending order
            swap(nums[i], nums[j]);
            i++;
        }
    }

    swap(nums[i], nums[right]); // Place pivot in its correct position
    return i;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left]; // Only one element left

    int pivotIndex = partition(nums, left, right);

    if (pivotIndex == k) return nums[pivotIndex]; // Found the k-th largest
    else if (pivotIndex < k) return quickSelect(nums, pivotIndex + 1, right, k);
    else return quickSelect(nums, left, pivotIndex - 1, k);
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k - 1);
}

// Main function to test the solution
int main() {
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    cout << findKthLargest(nums1, 2) << endl; // Expected: 5
    cout << findKthLargest(nums2, 4) << endl; // Expected: 4

    return 0;
}
