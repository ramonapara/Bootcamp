#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define THREADURI 10
pthread_mutex_t counterlock;
void *increment(void *index)
{
	 pthread_t id=pthread_self();
	//pthread_mutex_t counterlock;
	//pthread_mutex_init(&counterlock,NULL);
//	static long count=0;
	//pthread_mutex_lock(&counterlock);
//	long *count=(long *)index;
//	printf("count = %ln \n",count);
//	for(int i=0;i<10;i++)
//	{
		pthread_mutex_lock(&counterlock);
	//	pthread_t id=pthread_self();
		(*(int *)index)++;
		sleep(1);
		printf("thread = %ld counter = %d \n",id,*(int *)index);
		pthread_mutex_unlock(&counterlock);
//	}
	//pthread_mutex_unlock(&counterlock);
	return NULL;
}

int main()
{
	pthread_t threads[THREADURI];
	//pthread_mutex_t counterlock;
	pthread_mutex_init(&counterlock,NULL);
	int rc;
	long i;
	int nr=0;
	long t=0;
	int cresc=0;

	for(i=0;i<THREADURI;i++)
	{
		//printf("In main: count %ld \n",cresc);
	//	pthread_mutex_lock(&counterlock);
		printf("In main: thread %ld \n",i);
	//	sleep(1);
		rc=pthread_create(threads+i,NULL,&increment,(void*)&cresc);
	//	pthread_mutex_unlock(&counterlock);
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

	//pthread_mutex_destroy(&counterlock);

	pthread_exit(NULL);

	return 0;
}
