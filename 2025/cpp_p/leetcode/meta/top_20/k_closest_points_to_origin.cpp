// Problem: 973. K Closest Points to Origin
// Given an array of points where points[i] = [xi, yi] represents a point on the XY-plane,
// return the k closest points to the origin (0, 0).
// The distance between two points (x1, y1) and (x2, y2) is defined as the Euclidean distance:
// sqrt((x2 - x1)^2 + (y2 - y1)^2). You may assume k is always valid, 1 <= k <= number of points.

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap to store points based on their squared distance from the origin
        priority_queue<pair<int, vector<int>>> maxHeap;

        // Calculate squared distance and push into the max-heap
        for (auto& point : points) {
            int dist = point[0] * point[0] + point[1] * point[1]; // Squared distance
            maxHeap.push({dist, point});
            if (maxHeap.size() > k) {
                maxHeap.pop(); // Keep only the k closest points
            }
        }

        // Extract the points from the heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> points1 = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k1 = 2;
    vector<vector<int>> res1 = sol.kClosest(points1, k1);
    for (const auto& point : res1) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl; // Output: [[-2, 2], [0, 1]]

    // Test case 2
    vector<vector<int>> points2 = {{3, 3}, {5, -1}, {-2, 4}};
    int k2 = 2;
    vector<vector<int>> res2 = sol.kClosest(points2, k2);
    for (const auto& point : res2) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl; // Output: [[3, 3], [-2, 4]]

    return 0;
}
