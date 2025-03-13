#include <iostream>
#include <vector>
#include <cstdlib> // for rand()

using namespace std;

// Helper function for partitioning the array around a pivot
int partition(vector<int>& nums, int left, int right) {
  int pivot = nums[right];
  int i = left;  // Start i from left instead of left - 1
  
  for (int j = left; j < right; ++j) {
      if (nums[j] > pivot) { // We want the kth largest, so we compare greater than pivot
          swap(nums[i], nums[j]);
          ++i;
      }
  }
  
  swap(nums[i], nums[right]); // Move the pivot into its correct position
  return i;
}

int quickselect(vector<int>& nums, int left, int right, int k) {
  if (left == right) return nums[left];
  
  // Randomly choose a pivot
  int pivotIndex = left + rand() % (right - left + 1);
  swap(nums[pivotIndex], nums[right]);
  
  // Partition the array around the pivot
  int partitionIndex = partition(nums, left, right);
  
  // If the partition index is the kth largest element, return it
  if (partitionIndex == k) {
      return nums[partitionIndex];
  }
  // Otherwise, recurse in the appropriate half
  else if (partitionIndex < k) {
      return quickselect(nums, partitionIndex + 1, right, k);
  } else {
      return quickselect(nums, left, partitionIndex - 1, k);
  }
}

int findKthLargest(vector<int>& nums, int k) {
  int n = nums.size();
  // Convert k to the index of the kth largest element
  return quickselect(nums, 0, n - 1, k - 1);
}

int main() {
    // Test cases
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    
    cout << "3rd largest in nums1: " << findKthLargest(nums1, 2) << endl;  // Output: 4
    cout << "4th largest in nums2: " << findKthLargest(nums2, 4) << endl;  // Output: 4
    
    return 0;
}
