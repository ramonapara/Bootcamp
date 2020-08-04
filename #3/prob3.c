#include <stdio.h>
void progressCallback( int index, int dataSize)
{
	int rez=dataSize-index;
	float  percentage=(float)index/dataSize*100.0;
	printf("Procentaj curent: ");
	printf("%lf",percentage);
	printf("\n");
}

void handleData(void(*f)(int,int),char *data, int dataSize)
{
      int i;
      int index=0;
      for(i=0;i<dataSize;i++)
      {
	      printf("Date: ");
	      printf("%c",data[i]);
	      printf("\n");
	      index++;
	      (*f)(index,dataSize);
      }

}

int main()
{
	int dataSize;
	printf("dataSize = ");
	scanf("%d",&dataSize);
	printf("%d",dataSize);

	char *data;
	printf("data = ");
	scanf("%s",data);
	printf("%s",data);
	//idata=(char *)malloc(dataSize*sizeof(char));
	handleData(progressCallback,data,dataSize);

	return 0;
}


