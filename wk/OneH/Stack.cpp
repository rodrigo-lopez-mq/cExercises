#include <iostream>
#include <cstdlib>

template <typename T> class Stack 
{
    protected:
        
        class Node
        {
        public:
            T value;
            Node *left;
            Node *right;
            
            Node()
            {
                left=NULL;
                right=NULL;
                value=NULL;
            }
            Node(T x)
            {
                left=NULL;
                right=NULL;
                value=x;
            }
            
        };
        
    public:
        
        Node *head;
        
        Stack()
        {
            head=NULL;
        }
        
        void push(T value)
        {
            if(head==NULL)
            {
                head=new Node(value);
            }
            else
            {
                Node *next=new Node(value);
                next->right=head;
                head=next;
            }
        }
        
        T pop()
        {
            T ret = head->value;
            
            Node *old=head;
            head=old->right;
            delete(old);
            
            return ret;
        }
        
        void print()
        {
            if(head==NULL)
            {
                std::cout<<"Empty"<<std::endl;
            }
            else
            {
                Node *next=head;
                while(1)
                {
                    std::cout<<next->value<<std::endl;
                    if(next->right!=NULL)
                    {
                        next=next->right;
                    }
                    else
                    {
                        break;
                    }
                    
                }
                
            }
        }
        
        
        
        
};