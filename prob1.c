#include <stdio.h>
#include <stdint.h>

/* \fn	void printBits(uint32_t nr)
   \brief Iau numarul 'nr' si il scrie in baza 2 pe 32 de biti

   \param nr Numarul pentru care se face conversia.
*/
void printBits(uint32_t nr)
{
	uint32_t i;
	uint32_t a=1;
	uint32_t b=2;
	uint32_t rez;
	uint32_t count=0;
	uint32_t vect[50];

	for(i=0;i<32;i++)
	{
		///Fac o masca la fiecare iteratie dintre numar si muliplul lui 2
		rez=nr&a;
		///Trec la urmatorul multiplu al lui 2
		a=a<<1;
		///Duc bitul rezultatul pe ultimul loc, pentru a-l extrage
		rez=rez>>i;
		///Inserez intr-un vector toti bitii
		vect[i]=rez;
	}

	///Afisez numarul in ordine inversa 
	for(i=31;i>0;i--)
	{
		printf("%d",vect[i]);
	}
	printf("%d",vect[0]);
}

int main()
{
	uint32_t nr;
	printf("Dati numarul: ");
	scanf("%d",&nr);
	printBits(nr);
	return 0;
}
