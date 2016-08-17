#include <iostream>

using namespace std;

int onefunction(void * value)
{
	// cout<<"Yup"<<endl;

	cout<<*((int*)value)<<endl;
}

int twofunction(void*value)
{
	int e = 9;
	*(int*)(value) = e;

}

int main()
{

typedef void* qcarcam_hndl_t;

qcarcam_hndl_t y;

	int u = 6;
	y=&u;

	onefunction(y);

	twofunction(y);

	cout<<*((int*)y)<<" end"<<endl;


  	cout << "Suh"<<endl;
}
