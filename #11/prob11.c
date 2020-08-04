#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>

#define QUEUE_SIZE 10
#define THREADS 10
#define MAX 4

struct Nod{
        int data;
        struct Nod *succ;
};

struct Queue{
        struct Nod *head,*tail;
};

struct Queue *Q;
typedef struct _ENGINE_DATA{
        int nr_prod; //nr de producatori
        int nextin; //urm pozitie de produs
        int nextout; //urm pozitie de consumat
        char buffer[MAX];
        struct Queue *Q;
}ENGINE_DATA;

//static struct Queue *Q;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
static pthread_t consumer;
static int v = 0;

void init(struct Queue *Q)
{
        Q->head=Q->tail=NULL;
}

int isEmpty(struct Queue *Q)
{
//	printf("EMPTY \n");
	if(Q!=NULL)
	{

        	return(Q->tail==NULL);
	}
	else
	{
		return 0;
	}
}

static void Put(struct Queue *Q, int val) 
{
//	init(Q);
//	printf("PUT1 \n");
	struct Nod *p;
        p=(struct Nod *)malloc(sizeof(struct Nod));
        p->data=val;
//	printf("p->data = %d \n",p->data);
        p->succ=NULL;
//	printf("PUT 2 \n");

        pthread_mutex_lock(&lock2);
        if(isEmpty(Q)==0)
        {
//		printf("PUT 3 \n");
                Q->tail->succ=p;
//		printf("PUT 4 \n");
                Q->tail=p;
//		printf("PUT 5 \n");
        }
        else
        {
                Q->tail=p;
//		printf("Q->tail->data = %d \n",Q->tail->data);
//		printf("PUT 6 \n");
                Q->head=p;
//		printf("PUT 7 \n");

        }
	pthread_mutex_unlock(&lock2);

}


static int Pop(struct Queue *Q) 
{  
//       printf("POP FUNCTIE \n");	
	struct Nod *p;
        int aux;
        if(!isEmpty(Q))
        {
                pthread_mutex_lock(&lock2);
                p=Q->head;
                aux=p->data;
                Q->head=p->succ;
		Q->tail=p->succ;
                pthread_mutex_unlock(&lock2);
         	free(p);
         //       return aux;
        }
        else
        {
                printf("Coada goala!!");
        }
//	free(p);
	return aux;

}

int Top(struct Queue *Q)
{
        int aux;
        if(!isEmpty(Q))
        {
                return Q->head->data;
        }
        else
        {
                return 0;
        }
}

int  initializeEngine(ENGINE_DATA *engine)
{
        engine->nr_prod=0;
        engine->nextin=1;
        engine->buffer[engine->nextin]='0';
        return engine->nr_prod;
}


static void *produce(void *args) 
{
     int *value = (int *) args;

    pthread_mutex_lock(&lock);

    printf("Thread id: %lu - value: %d\n", pthread_self(), *value);
    Put(Q, *value);
    (*value)++;
    printf("%d",*value);

    pthread_mutex_unlock(&lock);

    return NULL;
}

static void *on_consume(void *args) 
{

    pthread_mutex_lock(&lock);

    while (!isEmpty(Q)) 
    {
        printf("Consumer popped from queue value: %d\n", Pop(Q));

    }

    pthread_mutex_unlock(&lock);

    return NULL;

}

static void start_engine() 
{
    pthread_create(&consumer, NULL, on_consume, NULL);
}

static void stop_engine() 
{
    pthread_join(consumer, NULL);
}

static void destroy_engine() 

{

    if (NULL != Q) 

    { 

        free(Q);

        Q= NULL;

    }

    else 

    {

        printf("The queue is NULL.");

    }

}


int a=10;
int main() 
{

    int i = 0;
    pthread_t producers[THREADS];
    Q = (struct Queue *) malloc (sizeof(struct Queue));	   
    init(Q);
 //   printf("%ld",sizeof(struct Queue));
   // printf("%d",a);
//    Put(Q,5);
//    initializeEngine();

//    if (NULL != Q) 
  //  {
        for (i = 0; i < 10; i++) 
        {
            pthread_create(&producers[i], NULL, produce, &v);
        }

        for (i = 0; i < 10; i++)
        {
            pthread_join(producers[i], NULL);
        }

        start_engine();

        stop_engine();

        destroy_engine();
  //  }
  //  else 
   // {
    //    printf("The queue is NULL.");
  //  }

        return 0;

}
