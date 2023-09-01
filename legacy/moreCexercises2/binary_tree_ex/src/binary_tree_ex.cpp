#include <iostream>
#include <cstring>
// #include <stdlib.h>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int node_value;

    Node(int value) : left(nullptr), right(nullptr), node_value(0)
    {
        node_value = value;
    }
};


int main(int argc, char *argv[])
{
    cout << "START TESTING" <<endl;

    


    cout << "END TESTING" <<endl;

    return 0;
}