#include  <stdio.h>

#include <string.h>
#include <stdlib.h>

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
			system("cat prob13.c > fisier2.c");
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
			char i,i2;
			insertf=fopen("prob13.c","r");
			aux=fopen("aux.c","w+");

			if(aux==NULL)
			{
				printf("Eroare");
				break;
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
					}
					else
					{
						fprintf(aux,"%s\n",text_de_inserat);
			
					}
				}
			}
			//while( ( i2 = fgetc(aux) ) != EOF )
     			//	 fputc(i2, insertf);
			fclose(insertf);
			fclose(aux);
			break;
		case 'D':
			printf("Ati ales optiunea Delete text from position \n");
			printf("Introduceit pozitia de la care doriti sa stergeti: \n");
			scanf(" %d \n",&pozitie_de_sters);
			printf("Introduceti numarul de caractere pe care doriti sa le stergeti: \n");
			scanf(" %d \n",&nr_caractere);
			int caractere=0;
			char k,j;
			char space='3';

			FILE *r=fopen("prob13.c","r");
			FILE *write=fopen("aux.c","w");

			if(r == NULL || write == NULL)
			{
				printf("Eroare la deschidere fisier. \n");
				break;
			}

			while((k=fgetc(r))!=EOF)
			{
				caractere++;
				if(caractere == pozitie_de_sters)
				{
					while((j=fgetc(write))!=EOF)
					{
						if(k==j && nr_caractere!=0)
						{
							printf("Am gasit unul din caractere \n");
							j=space;
							nr_caractere--;
						}
					}
				}
			}
			break;
		case 'U':
			printf("Ati ales optiunea Undo \n");
			FILE *fisier1=fopen("aux.c","w+");
			FILE *fisier2=fopen("undo.c","w+");
			char read[80];
			//
			//printf("textul inserat era: %s",text_de_inserat);

			char t[]="ramona";
			rewind(fisier1);
			while(!feof(fisier1))
			{
				fscanf(fisier1,"%s",read);
				//printf("%s \n",read);
				if(strcmp(read,t)==0)
				{
					printf("Am gasit cuvantul! ");
					strcpy(read," ");
					fprintf(fisier1,"%s",read);
					
				}
				//fprintf(fisier2," %s \n ",read);
			}
			fclose(fisier1);
			fclose(fisier2);
			break;
		case 'R':
			printf("Ati ales optiunea Redo. \n");




	}


	return 0;
}



