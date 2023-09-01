#include <iostream>
#include <cstring>
#include <vector>
// #include <stdlib.h>

using namespace std;

class Binary_heap
{
    vector<int> m_storage;

public:
    Binary_heap()
    {

    }
    ~Binary_heap()
    {
        m_storage.clear();
    }
    int insert(int value)
    {
        int rc = 0;
        int ret = 0;
        int temp_index = 0;


        m_storage.push_back(value);
        temp_index = m_storage.size() - 1;

        if (temp_index == 0)
        {
            ret = 1;
        }
        if (ret == 0)
        {
            if (m_storage[temp_index] < m_storage[(temp_index - 1) / 2])
            {
                
            }
        }
        
        return 0;
    }
    int print_all()
    {
        int temp_size = m_storage.size();
        for(int i = 0; i < temp_size; i++)
        {
            cout << m_storage[i] << "\t";
        }
        cout << endl; 

        for(int i = 0; i < temp_size; i++)
        {
            cout << i << "\t";
        }
        cout << endl;

        return 0;
    }
};

int main(int argc, char *argv[])
{
    cout << "START TESTING" <<endl;

    Binary_heap test_heap;

    test_heap.insert(1);
    test_heap.insert(3);
    test_heap.insert(5);
    test_heap.insert(6);
    test_heap.insert(8);
    test_heap.insert(9);

    test_heap.print_all();




    cout << "END TESTING" <<endl;

    return 0;
}