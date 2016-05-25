#include <iostream>
#include <cstring>
#include <cstdarg>

using namespace std;

template <typename T> class SingleList
{
    class Node
    {
    public:
        T value;
        Node *next;

        Node()
        {
            next=NULL;
        }
    };

    Node *head;

public:

    SingleList()
    {
        head=NULL;
    }

    void print()
    {
        Node *next=head;
        while(next)
        {
            cout<<next->value<< " ";
            next=next->next;
        }
        cout<<endl;
    }

    void append(T v)
    {

        if(!head)
        {
            Node *node=new Node();
            node->value=v;
            head=node;
            //cout<<"d";

        }
        else
        {
            Node *next = head;

            while (next->next)
            {
                next = next->next;
            }
            Node *node=new Node();
            node->value=v;
            next->next=node;

        }
    }

    void reverse()
    {
        if(!head){return;}
        Node *root=head;
        Node *thenew=NULL;
        Node *next=NULL;

        while(root)
        {
            next=root->next;
            root->next=thenew;
            thenew=root;
            root=next;
        }
        head=thenew;

    }

};



int main()
{
    SingleList<int> *lista=new SingleList<int>();

    lista->append(1);
    lista->append(2);
    lista->append(3);
    lista->append(4);
    lista->append(5);

    lista->reverse();

    lista->print();



    delete(lista);

    cout<<"\n";
    //cout<<i;
}
