#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef struct _COMPONENT_DATA
{
	int attributes;
	char *name;
	size_t nameSize;
}COMPONENT_DATA,*PCOMPONENT_DATA;

//1
void  serializeData(COMPONENT_DATA *componentInfo,void *buffer, size_t bufferSize)
{
	memcpy(buffer,&componentInfo->attributes,sizeof(componentInfo->attributes));
	memcpy(buffer+sizeof(componentInfo->attributes),&componentInfo->nameSize,sizeof(componentInfo->nameSize));
	memcpy(buffer+sizeof(componentInfo->nameSize)+sizeof(componentInfo->attributes),componentInfo->name,sizeof(componentInfo->name));

	uint8_t *rez = (uint8_t*) buffer;
	for(int i=0;i<83;i++)
	{
		printf("%02x \n",((uint8_t*)buffer)[i]);
	}
}

//2
int deserializeData(void *buffer,size_t bufferSize,COMPONENT_DATA *componentInfo)
{
	int *ptr1,*ptr2,*ptr3;

	memcpy(&componentInfo->attributes,buffer,sizeof(componentInfo->attributes));
	printf("%d \n",componentInfo->attributes);
//	printf("1 memcpy ==== %d \n",*ptr1);
//	componentInfo->attributes=*ptr1;
//	printf("componentInfo->attributes = %d \n",componentInfo->attributes);

	memcpy(&componentInfo->nameSize,buffer+sizeof(componentInfo->attributes),sizeof(componentInfo->nameSize));
	printf("%ld \n",componentInfo->nameSize);
//	printf("2 memcpy ==== %d \n",*ptr2);
//	componentInfo->nameSize=*ptr2;
//	printf("componentInfo->nameSize = %ld \n",componentInfo->nameSize);

//	memcpy(ptr3,buffer+sizeof(componentInfo->nameSize),sizeof(componentInfo->name));
//	componentInfo->name=*ptr3;
//	strcpy(componentInfo->name,*ptr3);

	memcpy(componentInfo->name,buffer+sizeof(componentInfo->nameSize)+sizeof(componentInfo->attributes),sizeof(componentInfo->name));
	printf("componentInfo->name = %s \n",componentInfo->name);	
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

	void *buffer=(void*)malloc((sizeof(COMPONENT_DATA)+3)*3);

//	printf("Dimensiunea buffer ului = %ld \n",(sizeof(COMPONENT_DATA)+3)*3);
	serializeData(componentInfo,buffer,(sizeof(COMPONENT_DATA)+3)*3);
                   
	int rez=deserializeData(buffer,(sizeof(COMPONENT_DATA)+3)*3,componentInfo);
	printf("\n");
	printf("IN MAIN, DUPA DESERIALIZARE: \n");
	printf("componentInfo->attributes = %d \n",componentInfo->attributes);
	printf("componentInfo->nameSize = %ld \n",componentInfo->nameSize);
	printf("componentInfo->name = %s \n",componentInfo->name);
	return 0;
}
	


	
