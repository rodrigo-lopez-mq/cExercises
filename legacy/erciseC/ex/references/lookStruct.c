
#include <stdio.h>

struct Books {
	int one;
	int two;
   int   book_id;
};  

static struct Books regs[] =
{
	/* Global Settings */
	{ 0x10, 0x81, 0},
	{ 0x11, 0x85, 0},
	{ 0x12, 0x89, 0},
	{ 0x13, 0x8d, 0},
	{ 0x1f, 0x6, 0},
	{ 0x32, 0x1, 0},
	{ 0x33, 0x1, 0},
	{ 0x4c, 0x1, 0},
	{ 0x6e, 0x8, 5000},
	{ 0x6e, 0x9, 5000},
	{ 0x70, 0x1f, 0},
	{ 0x58, 0x58, 0},
	{ 0x5c, 0x18, 0},
	{ 0x5d, 0x60, 0},
	{ 0x65, 0x48, 0},
	{ 0x7c, 0x81, 0},
	{ 0x6f, 0x8, 0},
	{ 0x6d, 0x7f, 0}, };

main()
{
    printf("SUP\n");
    printf("%X\n",regs[0].two);

}