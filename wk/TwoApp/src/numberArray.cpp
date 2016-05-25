#include <iostream>
int *mulArray(int *input, int size)
{
	int product_so_far=*input;
	int product_except_index[size];
	int *result=product_except_index;

//	int array[]={1,7,3,4};


	for (int i=0;i<size;i++)
	{
		product_except_index[i]=4;//product_so_far;
		product_so_far*=*input;
		std::cout<<product_except_index[i]<<std::endl;
	}


	return input;
}
