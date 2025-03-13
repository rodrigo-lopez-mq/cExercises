#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/**
 * Problem: Given the root of a binary tree, return the vertical order traversal of its nodes' values.
 * The traversal should be from top to bottom, column by column.
 * If two nodes are in the same row and column, the order should be from left to right.
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalOrder(TreeNode* root) {
    if (root == nullptr) return {}; // If the tree is empty, return empty result.

    // A map to store the vertical order of nodes by their horizontal distance (column index)
    map<int, vector<int>> columnTable;
    // Queue to store the nodes along with their horizontal distance (column index)
    queue<pair<TreeNode*, int>> q;

    // Start with the root node at column 0
    q.push({root, 0});
    
    while (!q.empty()) {
        int size = q.size();
        
        // Process all nodes at the current level
        for (int i = 0; i < size; ++i) {
            auto [node, column] = q.front();
            q.pop();
            
            // Add the node value to the appropriate column in the map
            columnTable[column].push_back(node->val);
            
            // If the left child exists, push it to the queue with column index - 1
            if (node->left) {
                q.push({node->left, column - 1});
            }
            
            // If the right child exists, push it to the queue with column index + 1
            if (node->right) {
                q.push({node->right, column + 1});
            }
        }
    }
    
    // Extract the result from the columnTable in order of column index
    vector<vector<int>> result;
    for (auto& entry : columnTable) {
        result.push_back(entry.second);
    }
    
    return result;
}

// Main function to test the solution
int main() {
    // Example 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    
    vector<vector<int>> result1 = verticalOrder(root1);
    for (const auto& col : result1) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Example 2
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(8);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(0);
    root2->right->left = new TreeNode(1);
    root2->right->right = new TreeNode(7);

    vector<vector<int>> result2 = verticalOrder(root2);
    for (const auto& col : result2) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
