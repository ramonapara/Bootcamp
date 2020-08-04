#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#define THREADURI 10
pthread_mutex_t mutex;
int semnal=0;

void signal_handler(int sig)
{
	semnal=1;
	printf(" S-a schimbat \n");
	printf("Semnal = %d \n",semnal);
}

void *fun(void *index)
{
	static long count=0;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		count++;
		sleep(1);
		printf("Nr = %ld \n",count);
		pthread_mutex_unlock(&mutex);
		if(semnal == 1)
		{
			pthread_exit(&count);
		}
		//pthread_exit(&count);
	}
	pthread_exit(&count);
	return NULL;
}

int main()
{
	pthread_t threads[THREADURI];
	int rc;
	long i;
	int *ptr[10];


	for(i=0;i<THREADURI;i++)
	{
		if(semnal==0)
		{
			pthread_mutex_lock(&mutex);
                	//signal(SIGINT,sig_intr);
			signal(SIGINT,signal_handler);
                	printf("In main: thread %ld \n",i);
                	sleep(1);
                	rc=pthread_create(threads+i,NULL,&fun,NULL);
                	pthread_mutex_unlock(&mutex);
                	if(rc)
                	{
                        	printf("Error: return code from pthread_create() is %d \n",rc);
                        	exit(-1);
   			}
		}
		else
		{
			break;
		}
	}

	for (i=0;i<THREADURI;i++)
	{
		pthread_join(threads[i],(void**)&(ptr[i]));
	}
	printf("Valoarea returnata este: %d \n",*ptr[0]);
	pthread_exit(NULL);
}
