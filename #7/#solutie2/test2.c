include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "example.h"
#include <dlfcn.h>

/// gcc -o  test2 test2.c -L. -lexample -ldl
/// echo $LD_LIBRARY_PATH
/// export LD_LIBRARY_PATH=.
/// echo $LD_LIBRARY_PATH
/// ./test2
int main()
{
	void *example2;
//	int eret;
	example2=dlopen("libexample.so",RTLD_LOCAL | RTLD_LAZY);
	if(!example2)
	{
		fprintf(stderr,"dlopen err: %s \n",dlerror());
		exit(EXIT_FAILURE);
	}
	void *symbol=dlsym(example2,"allocInLib");
	printf("allocInLib: %p \n",symbol);


	int *x=allocInLib();
	freeInLib(x);
//	eret=dlclose(example2);
	return 0;
}

