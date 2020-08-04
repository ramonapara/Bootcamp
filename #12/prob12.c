#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nod{
        char *cuvant;
        int frecventa;
        struct Nod *succ;
};

int isEmpty(struct Nod *cap)
{
        if(cap==0)
        {
                //cout<<"Lista goala!";
                return 0;
        }
        else
        {
                return 1;
        }
}
void insert(struct Nod **cap,char *v)
{
        struct Nod *temp;
	temp=*cap;
        int ok=0;

        if(isEmpty(temp)!=0)
    	{
	       while(temp)
	       {
                        if(strcmp(temp->cuvant,v)==0)
                        {
                                temp->frecventa++;
                                ok=1;
                        }
                        temp=temp->succ;
                }
        }
        if(ok==0)
        {
                if(isEmpty(*cap)==0)
                {
                         *cap=malloc(sizeof(struct Nod));
                         (*cap)->cuvant=v;
                         (*cap)->frecventa=1;
                }
                else
                {
                        struct Nod *p=malloc(sizeof(struct Nod));
                        p->cuvant=v;
                        p->frecventa=1;
                        p->succ=*cap;
                        *cap=p;
                }
        }
}

void afisare(struct Nod *cap)
{
        while(cap)
        {
                printf(" %s ",cap->cuvant);
               	printf(" %d ",cap->frecventa);
		printf("\n");
                cap=cap->succ;
        }
}

void sortare(struct Nod **cap)
{
        struct Nod *temp1=malloc(sizeof(struct Nod));
        temp1=*cap;
        struct Nod *temp2=malloc(sizeof(struct Nod));
        temp2=*cap;

        while(temp1)
        {
                while(temp2)
                {
                        if(temp1->frecventa>temp2->frecventa)
                        {
                                struct Nod *aux=malloc(sizeof(struct Nod));
                                aux->frecventa=temp1->frecventa;
                                aux->cuvant=temp1->cuvant;

                                temp1->frecventa=temp2->frecventa;
                                temp1->cuvant=temp2->cuvant;
                                temp2->frecventa=aux->frecventa;
                                temp2->cuvant=aux->cuvant;
                        }
                        temp2=temp2->succ;
                }
                temp2=*cap;
                temp1=temp1->succ;
        }
}

int main()
{
        struct Nod *lista=0;
        char *cuvinte[6]={"sa","vedem","daca","merge","sa","daca"};
       for(int i=0;i<6;i++)
        {
                insert(&lista,cuvinte[i]);
        }

        sortare(&lista);
        afisare(lista);

        return 0;
}

