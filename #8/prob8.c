#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define THREADURI 10
//8. [Threads , callbacks variable passing] Implement using pthreads an application that starts 10 worker threads , passes an incremented index as value to each thread callback , lists the parameter from each thread , and waits for them

void *increment(void *index)
{
	long tid;
	tid=(long)index;
	printf("Index: %ld \n",(long)index);
	tid++;
	sleep(2);
	printf("Increment: %ld  \n",tid);
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[THREADURI];
	int rc;
	long i;
	int nr=0;

	for(i=0;i<THREADURI;i++)
	{
		printf("In main: thread %ld \n",i);
		rc=pthread_create(threads+i,NULL,increment,(void *)i);
		if(rc)
		{
			printf("Error: return code from pthread_create() is %d \n",rc);
			exit(-1);
		}
	}

	for (i=0;i<THREADURI;i++)
	{
		pthread_join(threads[i],NULL);
	}

	pthread_exit(NULL);

	return 0;
}

