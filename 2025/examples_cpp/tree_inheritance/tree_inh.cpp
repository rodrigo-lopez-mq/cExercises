#include <iostream>
#include <string>

// Base class Node
class Node {
public:
    Node* left;
    Node* right;

    // Virtual function to get the type of node
    virtual std::string getType() = 0;

    // Virtual function to print the value of the node
    virtual void printValue() = 0;

    // Constructor
    Node() : left(nullptr), right(nullptr) {}
};

// Derived class StringNode
class StringNode : public Node {
private:
    std::string value;

public:
    // Constructor
    StringNode(const std::string& val) : value(val) {}

    // Implementation of getType function
    std::string getType() override {
        return "String";
    }

    // Implementation of printValue function
    void printValue() override {
        std::cout << value;
    }
};

// Derived class IntNode
class IntNode : public Node {
private:
    int value;

public:
    // Constructor
    IntNode(int val) : value(val) {}

    // Implementation of getType function
    std::string getType() override {
        return "Int";
    }

    // Implementation of printValue function
    void printValue() override {
        std::cout << value;
    }
};

// Function to print the values of the tree
void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    printTree(root->left);
    std::cout << "Type: " << root->getType() << ", Value: ";
    root->printValue();
    std::cout << std::endl;
    printTree(root->right);
}

int main() {
    // Create nodes
    StringNode* stringNode1 = new StringNode("Hello");
    StringNode* stringNode2 = new StringNode("World");
    IntNode* intNode1 = new IntNode(10);
    IntNode* intNode2 = new IntNode(20);

    // Create binary tree structure
    stringNode1->left = intNode1;
    stringNode1->right = intNode2;
    intNode1->left = stringNode2;

    // Print the values of the tree
    printTree(stringNode1);

    // Deallocate memory
    delete stringNode1;
    delete stringNode2;
    delete intNode1;
    delete intNode2;

    return 0;
}