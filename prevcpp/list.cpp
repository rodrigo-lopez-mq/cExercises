template <typename T> class List
{
    class Node
    {
    public:
        T value;
        Node *right;
        Node *left;


        Node(T val)
        {
            value=val;
            right=NULL;
            left=NULL;
        }
    };

public:
    Node *head;
    Node *tail;

    List()
    {
        head=NULL;
        tail=NULL;
    }

    void append(T x)
    {
        if (head==NULL)
        {
            head=new Node(x);
            //head->left=NULL;
            head->right=head;
            tail = head;
        }
        else
        {
            Node *temp = new Node(x);
            tail->right=temp;
            temp->left=tail;
            tail=temp;
        }
    }

    void print()
    {
        Node *next=head;
        while(next!=NULL)
        {
            cout<<next->value<<" ";
            next=next->right;
        }
    }

    void insert(int x, T value)
    {
        Node *next=head;

        if (x==0)
        {
            head->left=new Node(value);
            next->right=head;
            head=next;
        }
        else
        {
            for (int i=0;i<x;i++)
            {
                next=next->right;
            }
            Node *temp=new Node(value);
            next->right->left=temp;
            temp->right=next->right;
            next->right=temp;
            temp->left=next;

        }

    }

};