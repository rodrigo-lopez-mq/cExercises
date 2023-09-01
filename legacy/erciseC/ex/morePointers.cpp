#include <iostream>
#include <stdlib.h>
using namespace std;

typedef void * un;

void func2(const void *input)
{
    cout<<*((int*)input)<<endl;
}

un func3(int input)
{
    un uno;
    uno = &input;
    return uno;
}

int func4()
{
    void * poi;
    int x = 4;
    poi = &x;

    void *pointers_vcap = calloc(5,sizeof(void*));
    int array[5] = {1,2,3,4,5};

    for (int i = 0; i < 5; ++i)
    {
    	cout<<*((int*)pointers_vcap[i])<<endl;
    }

    free(pointers_vcap);

    cout<<*((int*)poi)<<endl;
}

int main()
{
    int x = 4;

    // func2(&x);

    x=5;
    un uno = func3(7);
    cout<<*((un*)uno)<<endl;

    func4();

    return 0;
}