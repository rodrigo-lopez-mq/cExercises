#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameter = 0;  // Stores the maximum diameter found

    int dfs(TreeNode* root) {
        if (!root) return 0; // Base case: null node has height 0

        // Recursively get heights of left and right subtrees
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);

        // Update the maximum diameter found so far
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};

// Helper function to create a simple test case
TreeNode* createTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

// Main function to test the solution
int main() {
    Solution solution;
    TreeNode* root = createTestTree();
    cout << "Diameter of Binary Tree: " << solution.diameterOfBinaryTree(root) << endl;
    return 0;
}
