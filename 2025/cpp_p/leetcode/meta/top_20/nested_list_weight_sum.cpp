#include <iostream>
#include <vector>
using namespace std;

/**
 * Problem: Given a nested list of integers, each element is either an integer or a list whose elements may also be integers or other lists.
 * The depth of an integer is the number of lists that it is inside of.
 * Return the sum of each integer in nestedList multiplied by its depth.
 */

// Interface for NestedInteger
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger() {}

    // Constructor initializes a single integer.
    NestedInteger(int value) : isInt(true), integer(value) {}

    // Return true if this NestedInteger holds a single integer.
    bool isInteger() const {
        return isInt;
    }

    // Return the single integer that this NestedInteger holds.
    int getInteger() const {
        return integer;
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        isInt = true;
        integer = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        isInt = false;
        nestedList.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds.
    const vector<NestedInteger>& getList() const {
        return nestedList;
    }

private:
    bool isInt = false;                // Flag to determine if it holds an integer
    int integer = 0;                   // Integer value
    vector<NestedInteger> nestedList;  // Nested list
};

// Recursive helper function to calculate depth sum
int depthSumHelper(const vector<NestedInteger>& nestedList, int depth) {
    int sum = 0;

    // Iterate through each element in the nested list
    for (const NestedInteger& element : nestedList) {
        if (element.isInteger()) {
            // If it's an integer, multiply by depth and add to sum
            sum += element.getInteger() * depth;
        } else {
            // If it's a nested list, recurse with increased depth
            sum += depthSumHelper(element.getList(), depth + 1);
        }
    }

    return sum;
}

// Main function to return depth sum
int depthSum(const vector<NestedInteger>& nestedList) {
    return depthSumHelper(nestedList, 1);  // Start at depth 1
}

// Main function to test the solution
int main() {
    // Example 1
    NestedInteger ni1;
    ni1.add(NestedInteger(1));
    ni1.add(NestedInteger(1));
    NestedInteger ni2(2);
    NestedInteger ni3;
    ni3.add(NestedInteger(1));
    ni3.add(NestedInteger(1));
    vector<NestedInteger> nestedList1 = {ni1, ni2, ni3};
    cout << "Example 1 Output: " << depthSum(nestedList1) << endl;  // Output: 10

    // Example 2
    NestedInteger ni4(1);
    NestedInteger ni5;
    ni5.add(NestedInteger(4));
    NestedInteger ni6;
    ni6.add(NestedInteger(6));
    ni5.add(ni6);
    vector<NestedInteger> nestedList2 = {ni4, ni5};
    cout << "Example 2 Output: " << depthSum(nestedList2) << endl;  // Output: 27

    // Example 3
    NestedInteger ni7(0);
    vector<NestedInteger> nestedList3 = {ni7};
    cout << "Example 3 Output: " << depthSum(nestedList3) << endl;  // Output: 0

    return 0;
}
