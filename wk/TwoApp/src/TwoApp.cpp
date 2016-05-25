#include <iostream>
#include "numberArray.h"
using namespace std;



int main() {

	int array[]={1,7,3,4};
	int *input=array;

	int *output=mulArray(input,(sizeof(array)/sizeof(int)));

	for(int i=0;i<(sizeof(array)/sizeof(int));i++)
	{
	cout<<*output++<<" ";
	}
	return 0;
}
