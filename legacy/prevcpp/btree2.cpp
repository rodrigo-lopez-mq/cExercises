#include <iostream>
//#include <cstring>
//#include <map>
//#include <string>

using namespace std;

class Bstree
{
public:

    class Node
    {
    public :
        int value=NULL;
        Node *right=NULL;
        Node *left=NULL;

        Node()
        {
            value=NULL;
        }

        Node(int v)
        {
            value=v;
        }
    };

    Node *head;

    Bstree()
    {
        head=NULL;
    }

    void insert(int x)
    {
        if (head==NULL)
        {
            head = new Node(x);
        }
        else
        {
            if(head->left==NULL)
            {
                head->left=new Node(x);
            }
            else if(head->right==NULL)
            {
                head->right=new Node(x);
            }
            else
            {
                if (x<head->value)
                {
                    insert(x,head->left);
                }
                else
                {
                    insert(x,head->right);
                }
            }
        }
    }

    void insert(int x,Node *node)
    {
        if(node->left==NULL)
        {
            node->left=new Node(x);
        }
        else if(node->right==NULL)
        {
            node->right=new Node(x);
        }
        else
        {
            if (x<node->value)
            {
                insert(x,node->left);
            }
            else
            {
                insert(x,node->right);
            }
        }
    }

    void print()
    {
        cout<<head->value<<endl;
        if (head->left!=NULL)
        {
            print(head->left);
        }
        if (head->right!=NULL)
        {
            print(head->right);
        }
    }
    void print(Node * next)
    {
        cout<<next->value<<endl;
        if (next->left!=NULL)
        {
            print(next->left);
        }
        if (next->right!=NULL)
        {
            print(next->right);
        }
    }

    float average()
    {
        int avg=0;
        //int n=1;
        int n=1;
        float res=0.0;
        avg=head->value;
        if (head->left!=NULL)
        {
            avg+=average(head->left);
            n+=size(head->left);
        }
        if (head->right!=NULL)
        {
            avg+=average(head->right);
            n+=size(head->right);
        }
        return (float)avg/(float)n;
    }
    int average(Node *next)
    {
        int avg=next->value;
        if (next->left!=NULL)
        {
            avg+=average(next->left);
        }
        if (next->right!=NULL)
        {
            avg+=average(next->right);
        }
        return avg;
    }
    int size(Node *next)
    {
        int n=1;
        if (next->left!=NULL)
        {
            n+=size(next->left);
        }
        if (next->right!=NULL)
        {
            n+=size(next->right);
        }
        return n;
    }

};

int main()
{



    Bstree *tree= new Bstree();
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);
    tree->insert(7);
    tree->insert(8);
    //tree->insert(9);

    //tree->print();
    cout<<tree->average()<<endl;
   delete tree;

    return 0;
}
