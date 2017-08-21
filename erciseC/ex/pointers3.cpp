#include <iostream>
#include <stdlib.h>
using namespace std;

void func1(void * input)
{
    for (unsigned int  i = 0; i < 5; ++i)
    {
        cout<<*((int*)input[i])<<endl;
        
    }
    
}

int main()
{

    void * void_pointer;
    int entero = 8;
    int *int_pointer= (int*)calloc(5,sizeof(int));
    int *int_pointer2= (int*)calloc(5,sizeof(int));
    void_pointer=int_pointer;

    void *pointers_vcap = calloc(5,sizeof(void*));

for (unsigned int  i = 0; i < 5; ++i)
    {

        int_pointer[i] = i;
        int_pointer2[i] = int_pointer[i];
        //pointers_vcap[i] = int_pointer[i];

        //*(int )(pointers_vcap[i]) = int_pointer2[i];

        //cout<<pointers_vcap[i]<<endl;
    }

    func1(int_pointer2);

    //cout<<*((int*)pointers_vcap[0])<<endl;


    return 0;
}