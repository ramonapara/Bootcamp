#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "example.h"
#include <dlfcn.h>

//gcc prob7.c example.so
//./a.out
//
// gcc -o myprogram prob7-project2.c -ldl -rdynamic
// gcc -fPIC -shared -o example.so prob7-project2.c
int  *allocInLib()
{
	int* ptr=(int *)malloc(sizeof(int));
	if(ptr==NULL)
	{
		printf("Ati alocat gresit. \n");
		exit(0);
	}
	else
	{
		printf("Ati alocat memorie corect! .\n");
		printf("Val: %d \n",*ptr);
	}
	return ptr;
}

void freeInLib(int *x)
{
	free(x);
	printf("Ati dealocat memoria pentru numar. \n");
}
