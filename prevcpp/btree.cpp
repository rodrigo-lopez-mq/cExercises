template <typename T> class Btree
{
    
    class Node
    {
        public:
        Node *right;
        Node *left;
        T value;

        Node()
        {
            right=NULL;
            left=NULL;
            value=NULL;
        }
        Node(T val,Node *l,Node *r)
        {
            right=r;
            left=l;
            value=val;
        }
    };
public:
    
    Node *root;
    
    Btree()
    {
        root=NULL;
    }
    
    void insert(T val)
    {
        if (root==NULL)
        {
            root=new Node(val,NULL,NULL);
        }
        
    }
    
};