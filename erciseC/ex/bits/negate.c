// number = 1

// length = (number + 4096 - 1) & ~(4096 - 1)

// print length

// print (~(4096 - 1))

#include <stdio.h>

main()
{
    printf("SUP\n");
    
    unsigned int number = 100;
    unsigned int length = (number + 4096 - 1) & ~(4096 - 1);

    unsigned int width,height,stride, size;
    width = 1280/2;
    height = 720/2;
    stride = width * 2;
    size = height * stride;

    length = (size + 4096 - 1) & ~(4096 - 1);
	printf(" = %x\n", size);
    printf(" = %x\n", length);

}