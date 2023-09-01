#include <iostream>
#include <cstring>
// #include <stdlib.h>

using namespace std;

class Node
{
public:
    Node *prev;
    Node *next;
    int node_value;

    Node(int value) : prev(nullptr), next(nullptr), node_value(0)
    {
        node_value = value;
    }
};

class Stack
{
    Node *start;
    Node *end;
    int m_size;

    int m_mode; // mode 0 is LIFO, mode 1 is FIFO

public:
    Stack(int mode = 0) :  start(nullptr), end(nullptr), m_size(0)
    {
        m_mode = mode;
    }
    ~Stack()
    {
        Node *temp = start;

        while(temp)
        {
            temp = temp->next;
            delete(start);
            start = temp;
            m_size--;
        }
    }
    int push(int value)
    {
        int rc = 0;

        Node *new_node = new Node(value);
        if (new_node == nullptr)
        {
            rc = -1;
        }
        
        if (start == nullptr)
        {
            start = new_node;
            end = new_node;
        }
        else
        {
            end->next = new_node;
            new_node->prev = end;
            end = new_node;
            m_size++;
        }

        return rc;
    }
    int pop()
    {
        int rc = 0;

        if (start == nullptr)
        {
            rc = -1;
        }
        if (rc == 0)
        {
            Node *temp = end->prev;

            if (m_mode == 0)
            {
                rc = end->node_value;

                temp->next = nullptr;
                delete(end);

                end = temp;
            }
            m_size--;
        }

        return rc;
    }
    int peek()
    {
        int rc = 0;

        if (start == nullptr)
        {
            rc = -1;
        }
        if (rc == 0)
        {
            if (m_mode == 0)
            {
                rc = end->node_value;
            }
        }

        return rc;
    }
    int print_all()
    {
        Node *temp = start;

        while(temp)
        {
            cout << "value : " << temp->node_value << endl;
            temp = temp->next;
        }
    }
};


int main(int argc, char *argv[])
{
    cout << "START TESTING" <<endl;

    Stack *stack_test = new Stack;

    cout << "TEST PUSH" <<endl;
    stack_test->push(2);
    stack_test->push(3);
    stack_test->push(4);
    stack_test->push(5);
    stack_test->push(6);

    stack_test->print_all();

    cout << "TEST_POP" <<endl;
    stack_test->pop();
    stack_test->pop();
    stack_test->pop();

    stack_test->print_all();


    cout << "END TESTING" <<endl;

    return 0;
}