#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdbool.h>
#include "hdr.h"


#define MAXOPEN 20 //numarul de cozi de masej deschise
#define MAXMSG 4 //numarul maxim de mesaje
#define KEY 1995

typedef enum {FALSE,TRUE} BOOLEAN;

struct msgbuf{
	long mtype;
	char mtext[256];
};

int openq(int key)
{
	struct {
		int key; //cheia fisierului
		int qid; //descript pt coada
	}q[MAXOPEN];
	int i,qid;
	 int errno;
	int avail=-1; //nu am gasit descipt valabil

	for(i=0;i<MAXOPEN;i++)
	{
		if(q[i].key==key)
		{
			return q[i].qid;
		}
		if(q[i].key == 0 && avail == -1)
		{
			avail=i;
		}
	}

	if(avail == -1)
	{
		errno=0;
		return -1;
	}

	if((qid=msgget(key,0666 | IPC_CREAT)) <0)
	{
		return -1;
	}
	q[avail].key=key;
	q[avail].qid=qid;
	return qid;
}

BOOLEAN send(int dstkey, struct msgbuf *buf, int nbytes)
{
	int qid;
	if((qid=openq(dstkey)) < 0)
	{
		fprintf(stderr,"Send - eroare open");
		return FALSE;
	}
	buf->mtype=1;
	return (msgsnd(qid,buf,nbytes-sizeof(buf->mtype),0)!=-1);
}

BOOLEAN receive(int srckey, struct msgbuf *buf, int nbytes)
{
	int qid;
	if((qid=openq(srckey)) <0 )
	{
		fprintf(stderr,"Receive -eroare open");
		return FALSE;
	}
	return (msgrcv(qid,buf,nbytes-sizeof(buf->mtype),0L,0)!=-1);
}

void deleteq(int key)
{
	int qid;
	if((qid=openq(key)) < 0 || msgctl(qid,IPC_RMID,NULL) <0)
	{
		err_sys("Eroare deleteq");
	}
}

int main()
{
	int pid;
	struct msgbuf mesaj;

	char *mes="Sa vedem daca merge";
	char *mes1="conti";

	//strcpy(mesaj.mtext,mes1);
	strcpy(mesaj.mtext,mes);
	//send(KEY,&mesaj,sizeof(mesaj));
	//send(KEY,&mesaj,sizeof(mesaj));
	//printf("Merge send! \n");
	//printf("\n");
	receive(KEY,&mesaj,sizeof(mesaj));
	//printf("Mesaje trimise: %s",mesaj.mtext);
	printf("Mesage primite: %s",mesaj.mtext);

	return 0;
}
