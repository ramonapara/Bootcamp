#include <stdio.h>
#include <stdlib.h>

struct Nod{
	int data;
	struct Nod *succ;
};

struct Queue{
	struct Nod *head,*tail;
};

void init(struct Queue  * Q)
{
	Q->head=Q->tail=NULL;
}

int isEmpty(struct Queue *Q)
{
	if(NULL == Q->head)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void Put(struct Queue *Q,int val)
{
	struct Nod *p;
	p=(struct Nod *)malloc(sizeof(struct Nod));
	p->data=val;
	p->succ=0;

	if(isEmpty(Q)==0)
	{
		Q->head=p;
		Q->tail=p;
	}
	else
	{
		Q->tail->succ=p;
		Q->tail=Q->tail->succ;

	}
}

int Pop(struct Queue *Q)
{
	struct Nod *p;
	int aux;

	if(NULL == Q->head)
	{
		printf("Coada goala!! \n");
	//	Q->tail=NULL;
//		printf("Q->tail %s \n" , (NULL==Q->tail)?"da":"nu");
  //      printf("Q->head %s \n" , (NULL==Q->head)?"da":"nu");
		return 0;
	}

	else
		p=Q->head;
		aux=p->data;
		Q->head=Q->head->succ;

//		> printf("Q->tail %s \n" , (NULL==Q->tail)?"da":"nu");
  //      printf("Q->head %s \n" , (NULL==Q->head)?"da":"nu");
		free(p);
		if(NULL == Q->head)
		{
			Q->tail=NULL;
		}
		 printf("Q->tail %s \n" , (NULL==Q->tail)?"da":"nu");
        printf("Q->head %s \n" , (NULL==Q->head)?"da":"nu");
		return aux;
}

int Top(struct Queue *Q)
{
	int aux;
	if(NULL != Q->tail)
	{
		return Q->head->data;
	}
	else
	{
		return 0;
	}
}	

int main()
{
	struct Queue *Q;
	Q=(struct Queue *)malloc(sizeof(struct Queue));
	init(Q);
	Put(Q,5);
	Put(Q,10);
	Put(Q,15);
//	printf("%d",Q->head->data);
//	printf("\n");
//	printf("%d",Q->tail->data);
	printf("\n");
//	int aux=Pop(Q);
//	printf("Valorea stearsa este: %d",aux);
	printf("\n");
	int aux1=Top(Q);
	printf("Valorea capului este: %d \n",aux1);
	printf("%d \n",Pop(Q));
	 printf("%d \n",Pop(Q));
	  printf("%d \n",Pop(Q));
	   printf("%d \n",Pop(Q));
	    printf("%d \n",Pop(Q));
	     printf("%d \n",Pop(Q));
	     printf("%d \n",Pop(Q));
	     printf("%d \n",Pop(Q));
	
	return 0;
}

