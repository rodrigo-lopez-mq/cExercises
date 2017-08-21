#include<iostream>
using namespace std;

typedef struct 
{
	int one;
	char pic;
}*capture_context_t;

typedef void* qcarcam_hndl_t;

void func(qcarcam_hndl_t hndl)
{

	capture_context_t context= (capture_context_t)hndl;

	cout<<context->pic<<endl;

}

int main()
{
    //cout <<""<<endl;

	capture_context_t  context;

	context->one=3;
	context->pic='y';

	qcarcam_hndl_t hndl = &context;

	func(hndl);

    return 0;
}