#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _COMPONENT_DATA
{
	int attributes;
	char *name;
	size_t nameSize;
}COMPONENT_DATA,*PCOMPONENT_DATA;

//1
void  serializeData(COMPONENT_DATA *componentInfo,unsigned char *buffer, size_t bufferSize)
{
	buffer[bufferSize]=componentInfo->attributes;
	printf("INTRA IN FUNCTIE %02x \n",buffer[bufferSize]);
	bufferSize++;
	buffer[bufferSize]='*';
	printf("INTRA IN FUNCTIE %c \n",buffer[bufferSize]);
	bufferSize++;

	buffer[bufferSize]=componentInfo->nameSize;
	printf("INTRA IN FUNCTIE %d \n",buffer[bufferSize]);
	bufferSize++;
	buffer[bufferSize]='!';
	printf("INTRA IN FUNCTIE %c \n",buffer[bufferSize]);
	bufferSize++;
	//buffer[bufferSize]=componentInfo->name;
	

	//memcpy(buffer,componentInfo->name,sizeof(int));
	strcpy(buffer,componentInfo->name);
	printf("INTRA IN FUNCTIE %s \n",buffer);
	bufferSize++;
	buffer[bufferSize]='~';
	printf("INTRA IN FUNCTIE %c \n",buffer[bufferSize]);
	
}

//2
int deserializeData(void *buffer,size_t bufferSize,COMPONENT_DATA *componentInfo)
{
	COMPONENT_DATA *aux=malloc(sizeof(COMPONENT_DATA));
	char *bufferRez;
	bufferRez=(char*)buffer;
	int nr=0;

	//printf("DESERIALIZARE %d \n",bufferRez[bufferSize+2]);
//	printf("DESERIALIZARE %c \n",bufferRez[bufferSize+3]);
	//printf("DESERIALIZARE %c \n",bufferRez[bufferSize+1]);
	//printf("DESERIALIZARE nr = %d \n",nr);
	while(nr<3)
	{
		if(bufferRez[bufferSize+1]=='*')
		{
			printf("DESERIALIZARE %d \n",bufferRez[bufferSize]); //5
			aux->attributes=bufferRez[bufferSize];
			//memcpy(aux->attributes,bufferRez,sizeof(int));
			bufferSize=bufferSize+2;
			nr++;
			printf("DESERIALIZARE %d \n", bufferRez[bufferSize]); //1
			printf("DESERIALIZARE %c \n",bufferRez[bufferSize+1]); //!
			printf("DESERIALIZARE nr = %d \n",nr); //nr=1
		}
	//	printf("%c",bufferRez[bufferSize-2]);

		if(bufferRez[bufferSize+1]=='!')
		{
			aux->nameSize=bufferRez[bufferSize];
			printf("DESERIALIZARE %d \n",bufferRez[bufferSize]);
			//memcpy(aux->name,bufferRez, sizeof(int));
		//	strcpy(bufferRez,aux->name);
		//	printf("DESERIALIZARE %s \n",bufferRez);
			bufferSize=bufferSize+2;
			printf("DESERIALIZARE %c \n",bufferRez[bufferSize+1]); //~
			printf("DESERIALIZARE %s \n",bufferRez);
			nr++;
			printf("DESERIALIZARE nr = %d \n",nr);
		}
		if(bufferRez[bufferSize+1]=='~')
		{
			aux->nameSize=bufferRez[bufferSize];
			//memcpy(aux->nameSize,bufferRez,sizeof(size_t));
			bufferSize=bufferSize+2;
			nr++;
			printf("DESERIALIZARE nr = %d",nr);
		}
	}

	if(nr==3)
	{
		return 1;
	}
	return 0;

}


int main()
{
	COMPONENT_DATA *componentInfo;//=malloc(sizeof(COMPONENT_DATA));
	componentInfo->attributes=5;
	strcpy(componentInfo->name,"A");
	componentInfo->nameSize=1;


	printf("IN MAIN : \n");
	printf("componentInfo->atributes ar trebui sa dea 5 = %d \n",componentInfo->attributes);
	printf("componentInfo->nameSize ar trebui sa fie 8 = %ld \n",componentInfo->nameSize);
	printf("componentInfo->name ar trebui sa dea A = %s \n",componentInfo->name);

	char *buffer=(char*)malloc((sizeof(COMPONENT_DATA)+3)*3);

	printf("Dimensiunea buffer ului = %ld \n",(sizeof(COMPONENT_DATA)+3)*3);
	serializeData(componentInfo,buffer,((sizeof(COMPONENT_DATA)+3)*3));

	//or(int i=0;i<128;i++)
	//{
	//	printf(" %02x \n",buffer[i]);
	//}
	//printf("%d",buffer);
	//
	
	int rez=deserializeData(buffer,(sizeof(COMPONENT_DATA)+3)*3,componentInfo);
	printf("\n");
	printf("IN MAIN, DUPA DESERIALIZARE: \n");
	printf("componentInfo->attributes = %d \n",buffer[81]);
	printf("componentInfo->nameSize = %d \n",buffer[83]);
	printf("componentInfo->name = %s \n",buffer);
	return 0;
}
	


	
