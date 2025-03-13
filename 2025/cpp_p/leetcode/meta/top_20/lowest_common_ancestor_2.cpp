#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    
    Node(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node* lowestCommonAncestor(Node* p, Node* q) {
    Node* a = p;
    Node* b = q;

    while (a != b) {
        a = (a == nullptr) ? q : a->parent;
        b = (b == nullptr) ? p : b->parent;
    }

    return a;
}

// Main function to test the solution
int main() {
    Node* root = new Node(3);
    Node* n5 = new Node(5);
    Node* n1 = new Node(1);
    Node* n6 = new Node(6);
    Node* n2 = new Node(2);
    Node* n0 = new Node(0);
    Node* n8 = new Node(8);
    Node* n7 = new Node(7);
    Node* n4 = new Node(4);

    root->left = n5; n5->parent = root;
    root->right = n1; n1->parent = root;
    n5->left = n6; n6->parent = n5;
    n5->right = n2; n2->parent = n5;
    n1->left = n0; n0->parent = n1;
    n1->right = n8; n8->parent = n1;
    n2->left = n7; n7->parent = n2;
    n2->right = n4; n4->parent = n2;

    cout << lowestCommonAncestor(n5, n1)->val << endl; // Expected: 3
    cout << lowestCommonAncestor(n5, n4)->val << endl; // Expected: 5
    cout << lowestCommonAncestor(root, n2)->val << endl; // Expected: 3

    return 0;
}
