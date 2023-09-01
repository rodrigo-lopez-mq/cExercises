#include<stdio.h>

int suma(int *input, size_t size, int index)
{
	if (index < size){
		return *input + suma(input + 1, size, index + 1);
	}
	else
	{
		return 0;
	}
}

float average(int *input, size_t size)
{
	int sum = suma(input, size, 0);
	printf("sum: %d \n", sum);
	printf("size: %d \n", size);

	float ret = (float)sum / size;

	printf("average: %f \n", ret);

	return ret;
}

main()
{
    printf("Start \n");

    size_t size;
    int array[24] = {1,2,3,4,5,6};
    size = 6;

    float av = average(array,size);

    
    // printf("%d \n", array[6]);

    
}