#include <iostream>
#include <cstring>
// #include <stdlib.h>

using namespace std;


typedef struct node_t
{
    node_t* next;
    node_t* prev;
    int value;
}node_t;

typedef struct link_list_t
{
    node_t* head;
    node_t* tail;
    int size;
}link_list_t;

int sList_push_back(link_list_t *list, int value)
{
    node_t *new_node = (node_t*)calloc(1, sizeof(node_t));
    new_node->value = value;

    if (list->head == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
        
    }
    list->size++;

    return 0;
}

int sList_delete(link_list_t *list)
{
    node_t *temp_node = list->head;

    while(temp_node)
    {
        temp_node = temp_node->next;
        free(list->head);

        list->head = temp_node;
        list->size--;
    }

    return 0;
}

int sList_print_all(link_list_t *list)
{
    node_t *temp_node = list->head;

    while(temp_node)
    {
        cout << "VALUE " << temp_node->value <<endl;
        temp_node = temp_node->next;
    }

    return 0;
}

class Node
{
public:
    Node *next;
    Node *prev;
    int node_value;

    Node(int value) : next(nullptr), prev(nullptr), node_value(0)
    {
        node_value = value;
    }
};

class Link_list
{
    Node *head;
    Node *tail;
    int size;

public:
    Link_list() : head(nullptr), tail(nullptr), size(0)
    {
    }

    ~Link_list()
    {
        Node *temp; 
        while(head)
        {
            temp = head->next;
            delete(head);
            head = temp;
            size--;
        }
    }

    int List_push_back(int value)
    {
        Node *temp = new Node(value);

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;

        return 0;
    }

    int List_push_front(int value)
    {
        Node *temp = new Node(value);

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        size++;

        return 0;
    }

    int List_push_at(int value, int index)
    {
        int rc = 0;
        int pos = 0;

        if (index < 0 || index > size)
        {
            cout << "List_push_at : Index is more than list size" << endl;
            rc = -1;
        }

        if (rc == 0)
        {
            if (index == 0)
            {
                List_push_front(value);
            }
            else
            {
                Node *temp = head;
                Node *new_node = new Node(value);
                  
                while(temp)
                {
                    if (pos == index)
                    {

                        temp->prev->next = new_node;
                        new_node->prev = temp->prev;

                        temp->prev = new_node;                        
                        new_node->next = temp;

                        size++;
                        break;
                    }
                    temp = temp->next;
                    pos++;
                }
            }       
        }
        return rc;
    }

    int List_get_size()
    {
        return size;
    }

    int List_print_all()
    {
        Node *temp = head;

        while(temp)
        {
            cout << "value : " << temp->node_value << endl;
            temp = temp->next;
        }

        return 0;
    }
};


int main(int argc, char *argv[])
{
    cout << "START for CLASS" <<endl;

    Link_list *test_list = new Link_list();

    /* TEST push back */
    test_list->List_push_back(5);
    test_list->List_push_back(6);
    test_list->List_push_back(7);
    test_list->List_push_back(8);
    test_list->List_push_back(9);
    test_list->List_push_back(10);
    test_list->List_push_back(11);
    cout << "List size : " << test_list->List_get_size() << endl;

    /* TEST push front */
    test_list->List_push_front(4);
    test_list->List_push_front(3);
    test_list->List_push_front(2);
    test_list->List_push_front(1);
    test_list->List_push_front(0);
    cout << "List size : " << test_list->List_get_size() << endl;

    /* TEST push at */
    test_list->List_push_at(21, 2);
    test_list->List_push_at(22, 0);
    test_list->List_push_at(23, 5);
    test_list->List_push_at(24, 10);
    cout << "List size : " << test_list->List_get_size() << endl;

    test_list->List_print_all();

    delete test_list;
    cout << "END for CLASS" << endl;

    cout << "START for STRUCT" <<endl;

    link_list_t *test_list_two = (link_list_t*)calloc(1, sizeof(link_list_t));

    sList_push_back(test_list_two, 5);
    sList_print_all(test_list_two);
    sList_delete(test_list_two);

    free(test_list_two);

    cout << "END for STRUCT" <<endl;

    return 0;
}