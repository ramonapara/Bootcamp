#include <stdio.h>
#include "example.h"

//  gcc test.c example.o
//   gcc -o myprogram test.c example.o
//   ./myprogram
int main()
{
	printf("Hello world! \n");
	int *x=allocInLib();
	freeInLib(x);
	return 0;
}
