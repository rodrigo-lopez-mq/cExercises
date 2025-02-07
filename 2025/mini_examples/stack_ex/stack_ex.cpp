// stack_ex.cpp : Defines the entry point for the application.
//

#include "stack_ex.h"
#include <stdexcept>

using namespace std;

// Constructor
Stack::Stack() : topNode(nullptr), bottomNode(nullptr), size(0) {}

// Destructor
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Push an element onto the stack
void Stack::push(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        topNode = bottomNode = newNode;
    }
    else {
        newNode->prev = topNode;
        topNode->next = newNode;
        topNode = newNode;
    }
    ++size;
}

// Pop an element from the stack
int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }

    int value = topNode->data;
    Node* temp = topNode;
    topNode = topNode->prev;
    if (topNode) {
        topNode->next = nullptr;
    }
    else {
        bottomNode = nullptr;
    }
    delete temp;
    --size;
    return value;
}

// Peek at the top element without removing it
int Stack::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return topNode->data;
}

// Check if the stack is empty
bool Stack::isEmpty() const {
    return size == 0;
}

// Get the size of the stack
int Stack::getSize() const {
    return size;
}

Stack::Stack(const Stack& other) : topNode(nullptr), bottomNode(nullptr), size(0) {
    Node* current = other.bottomNode; // Start from the bottom
    while (current) {
        push(current->data); // Push each node's data onto the new stack
        current = current->next;
    }
}

Stack& Stack::operator=(const Stack& other) {
    if (this == &other) return *this; // Self-assignment check

    // Clear current stack
    while (!isEmpty()) {
        pop();
    }

    // Copy elements from other
    Node* current = other.bottomNode; // Start from the bottom
    while (current) {
        push(current->data);
        current = current->next;
    }

    return *this;
}

Stack::Stack(Stack&& other) noexcept
    // We use move here because it just transfers ownership without copying the pointer
    : topNode(std::move(other.topNode)), bottomNode(std::move(other.bottomNode)), size(other.size) {
    // Nullify the source object's pointers and reset size
    other.topNode = nullptr;
    other.bottomNode = nullptr;
    other.size = 0;
}

int main()
{
    Stack stack;
    try {
        stack.pop();
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the top element
    std::cout << "Top element: " << stack.peek() << std::endl;

    // Pop elements from the stack
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;

    // Check size and if stack is empty
    std::cout << "Stack size: " << stack.getSize() << std::endl;
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    // Push another element and check again
    stack.push(40);
    std::cout << "Top element: " << stack.peek() << std::endl;
    std::cout << "Stack size: " << stack.getSize() << std::endl;

    Stack stack2(stack);
    std::cout << "Top element: " << stack2.peek() << std::endl;
    Stack stack3;
    stack3 = stack;
    std::cout << "Top element: " << stack3.peek() << std::endl;

    Stack stack4(std::move(stack));
    std::cout << "Top element: " << stack4.peek() << std::endl;
    //std::cout << "Top element: " << stack.peek() << std::endl;

	return 0;
}
