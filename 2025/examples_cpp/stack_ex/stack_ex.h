#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

// Node structure for the stack
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Stack class definition
class Stack {
private:
    Node* topNode; // Pointer to the top node
    Node* bottomNode; // Pointer to the bottom node (optional for doubly-linked convenience)
    int size; // Tracks the size of the stack

public:
    // Constructor
    Stack();

    // Destructor
    ~Stack();

    // Push an element onto the stack
    void push(int value);

    // Pop an element from the stack
    int pop();

    // Peek at the top element without removing it
    int peek() const;

    // Check if the stack is empty
    bool isEmpty() const;

    // Get the size of the stack
    int getSize() const;

    // Copy Constructor
    Stack(const Stack& other);

    // Copy Assignment Operator
    Stack& operator=(const Stack& other);

    Stack(Stack&& other) noexcept;
    //Stack& operator=(const Stack& other) = delete; // No copying allowed
};

#endif // STACK_HPP
