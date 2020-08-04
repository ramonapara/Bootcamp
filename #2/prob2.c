
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>

/* \fn	uint32_t *getValue(char *buffer,int offset, int bufferSize)
   \brief Citesc din buffer de la o anumite pozitie

   \param buffer Buffer-ul de unde citesc
   	  offset Pozitia de la care incep sa citesc
	  bufferSize Dimensiunea buffer ului
*/

uint32_t *getValue(char *buffer,int offset, int bufferSize)
{
	int i;
	uint32_t citit=read(0,buffer,bufferSize);
	///Vector unde inserez elementele citite
	uint32_t *rez=(uint32_t *)malloc(sizeof(uint32_t));
	int k=0;

	if(citit>0)
	{
		for(i=offset;i<bufferSize;i++)
		{
			rez[k]=buffer[i];
			k++;
		}
	}
	return rez;
}

int main()
{
	int bufferSize,offset;

	printf("bufferSize = ");
	scanf("%d",&bufferSize);

	printf("offset = ");
	scanf("%d",&offset);

	char *buffer=(char*)malloc(bufferSize*sizeof(char));
	uint32_t *rez=getValue(buffer,offset,bufferSize);
	for(int i=0;i<bufferSize-offset;i++)
	{
		printf("%c",rez[i]);
	}
	return 0;
}
