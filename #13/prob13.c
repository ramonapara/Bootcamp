#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int val(int x)
{
	printf("\n");
	printf("Valoarea pentru redo este: %d \n",x);
	printf("\n");
	//return x;
}


static int ok=0;
int main()
{
	printf("---------------MENIU--------------- \n");
	printf("OPTIUNI: \n");
	printf("[O] => Open file \n");
       	printf("[S] => Save file \n");
	printf("[W] => Write text at position \n");
	printf("[D] => Delete text from position \n");
	printf("[U] => Undo \n");
	printf("[R] => Redo \n");
	char opt;
	char text_de_inserat[128];
	int pozitie_de_inserat,pozitie_de_sters,nr_caractere;
	char nume_fisier[128];
	printf("Introduceti optiunea dvs : ");
	scanf("%s",&opt);
	printf("\n");

	while(opt!='0')
	{
		switch(opt){
			case 'O':
				printf("Ati ales optiunea Open file. \n");
				system("ls");
				printf("Introduceti fisierul pe care doriti sa-l deschideti: ");
				scanf("%s",nume_fisier);
				//system("vim $nume_fisier");
				FILE *inputf;
				inputf=fopen(nume_fisier,"r+");
				if(inputf==NULL)
				{
					printf("ERROR ");
					break;
				}
				printf("Ati deschis cu succes fisierul! \n");
			case 'S':
				printf("Ati ales optiunea Save file. \n");
				system("cat prob13.c > aux.c");
				break;
			case 'W':
				printf("Ati ales optiunea Write text at position \n");
				printf("Introduceti textul pe care doriti sa il inserati: ");
				scanf("%s",text_de_inserat);
				printf("Textul de inserat este: %s",text_de_inserat);
				printf("\n");
				printf("Introduceti pozitia la care doriti sa il inserati: ");
				scanf("%d",&pozitie_de_inserat);
				printf("\n");

				FILE *insertf;
				FILE *aux;
				int nr=0;
				char i,i2,i3;
				insertf=fopen("prob13.c","r");
				aux=fopen("aux.c","r+");
				FILE *redo1=fopen("redo-write.c","w+");

				if(aux==NULL)
				{
					printf("Eroare");
					break;
				}

			 	if(redo1==NULL)
                        	{
                                	printf("Eroare deschidere redo-write.c");
                        	}
			
				if(insertf==NULL)
				{
					printf("Eroare");
					break;
				}
				else
				{
					while((i=fgetc(insertf))!=EOF)
					{
						nr++;
						if(nr!=pozitie_de_inserat)
						{
							fputc(i,aux);
							fputc(i,redo1);
						}
						else
						{
							fprintf(aux,"%s\n",text_de_inserat);
							fprintf(redo1,"%s",text_de_inserat);
			
						}
					}
				}
				int val1=1;
				val(val1);
				fclose(insertf);
				fclose(aux);
				break;
			case 'D':
				printf("Ati ales optiunea Delete text from position \n");
				printf("Introduceit pozitia de la care doriti sa stergeti: ");
				scanf(" %d ",&pozitie_de_sters);
				printf("\n");
				printf("Pozitia este %d ",pozitie_de_sters);
				printf("Introduceti numarul de caractere pe care doriti sa le stergeti: ");
				scanf(" %d ",&nr_caractere);
				int caractere=0;
				char k,j;
				char space=' ';
				char str;
	
				FILE *r=fopen("prob13.c","r");
				FILE *write=fopen("aux.c","w");
				FILE *redo_del=fopen("redo-delete.c","w");
	
				if(r == NULL || write == NULL || redo_del == NULL)
				{
					printf("Eroare la deschidere fisier. \n");
					break;
				}

				while((k=fgetc(r))!=EOF)
				{
					//strcpy(str,"\0");
					str=k;
					//if((j=fgetc(r))!=EOF)
					//{
						caractere++;
						if(caractere!=pozitie_de_sters)
						{
							fprintf(write,"%c",str);
							fprintf(redo_del,"%c",str);
						}
						else
							while((k=fgetc(r))!=EOF &&nr_caractere!=0)
							{
								fprintf(write,"%c",space);
								fprintf(redo_del,"%c",space);
								printf("nr_caractere = %d",nr_caractere);
								nr_caractere--;
							}
				}
				int val2=2;
				val(val2);
				break;
			case 'U':
				printf("Ati ales optiunea Undo \n");
				FILE *fisier1=fopen("prob13.c","r");
				FILE *fisier2=fopen("aux.c","w");
				char x,y;
				
				if(fisier1 == NULL || fisier2 == NULL)
				{
					printf("Eroare deschidere fisiere! \n");
					break;
				}

				while((x=fgetc(fisier1))!=EOF)
				{
					fprintf(fisier2,"%c",x);
				}
	
				break;
			case 'R':
				printf("Ati ales optiunea Redo. \n");
				int valredo;
				printf("Introduceti valoarea pe care o vedeti pentru Redo: ");
				scanf("%d",&valredo);
				if(valredo==1)
				{
					FILE *w=fopen("aux.c","w");
					FILE *q=fopen("redo-write.c","r");
					char v;
					printf("Anulati efectul ultimului Undo - a scrie ceva in fisier \n");
					while((v=fgetc(q))!=EOF)
					{
						fprintf(w,"%c",v);
					}
				}
				if(valredo==2)
				{
			 		FILE *o=fopen("aux.c","w");
					FILE *p=fopen("redo-delete.c","r");
					char l;
					printf("Anulati efectul ultimului Undo - a sterge ceva din fisier \n");
					while((l=fgetc(p))!=EOF)
					{
						fprintf(o,"%c",l);
					}
				}
				break;
				}
		printf("Introduceti optiunea dvs : ");
        	scanf("%s",&opt);

	}


	return 0;
}



