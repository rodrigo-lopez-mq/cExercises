// Problem: 1650. Lowest Common Ancestor of a Binary Tree III
// Given two nodes of a binary tree `p` and `q`, where each node has a parent pointer,
// return their lowest common ancestor (LCA).
// Each node has the following structure:
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* parent;
// };

#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int _val) : val(_val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node* q) {
        // Use two pointers technique to find the LCA
        Node* a = p;
        Node* b = q;

        // Move up until both pointers are the same
        while (a != b) {
            // When reaching the top, switch to the other node
            a = a ? a->parent : q;
            b = b ? b->parent : p;
        }

        return a;
    }
};

int main() {
    // Building a sample tree manually
    Node* root = new Node(3);
    Node* node5 = new Node(5);
    Node* node1 = new Node(1);
    Node* node6 = new Node(6);
    Node* node2 = new Node(2);
    Node* node0 = new Node(0);
    Node* node8 = new Node(8);
    Node* node7 = new Node(7);
    Node* node4 = new Node(4);

    root->left = node5; node5->parent = root;
    root->right = node1; node1->parent = root;

    node5->left = node6; node6->parent = node5;
    node5->right = node2; node2->parent = node5;

    node1->left = node0; node0->parent = node1;
    node1->right = node8; node8->parent = node1;

    node2->left = node7; node7->parent = node2;
    node2->right = node4; node4->parent = node2;

    Solution sol;

    // Test case 1: LCA of node7 and node4 is node2
    Node* lca1 = sol.lowestCommonAncestor(node7, node4);
    cout << lca1->val << endl; // Output: 2

    // Test case 2: LCA of node6 and node4 is node5
    Node* lca2 = sol.lowestCommonAncestor(node6, node4);
    cout << lca2->val << endl; // Output: 5

    // Test case 3: LCA of node6 and node8 is root (3)
    Node* lca3 = sol.lowestCommonAncestor(node6, node8);
    cout << lca3->val << endl; // Output: 3

    return 0;
}
