// Problem: 938. Range Sum of BST
// Given the root node of a binary search tree and two integers low and high,
// return the sum of values of all nodes with a value in the inclusive range [low, high].

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;

        // If current node's value is less than low, skip left subtree
        if (root->val < low)
            return rangeSumBST(root->right, low, high);

        // If current node's value is greater than high, skip right subtree
        if (root->val > high)
            return rangeSumBST(root->left, low, high);

        // Node is in range, include its value and check both subtrees
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

int main() {
    // Constructing BST:
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    Solution sol;

    // Test case 1
    cout << sol.rangeSumBST(root, 7, 15) << endl; // Output: 32

    // Test case 2
    cout << sol.rangeSumBST(root, 6, 10) << endl; // Output: 23

    return 0;
}
