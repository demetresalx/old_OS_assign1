#include "arraystructs.h"
#include <stdio.h>
#include "mymalloc.h"
#include "hash.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>


//YPOTYPWDHS KLHSH, FTIAXNEI ENAN PINAKA AKERAIWN
/*int main(void)
{
	int * magik = mymalloc(5*sizeof(int));
	int * magik2 = mymalloc(6*sizeof(int));
	int i;
	for (i=0; i<4; i++)
		magik2[i] = i;

	for (i=0; i<4; i++)
		printf("%d", magik2[i]);
	

	myfree(magik2);
	return 0;
}*/


//ELEGXOS OTI OI KOMBOI DOULEUOUN SWSTA
int main(void)
{
	int i, nodes_counted;
	listnode * tester;
	int * magik = mymalloc(2025);
	for (i=0; i<8; i++)
	{
		if(nii->array[i].head == NULL)
			printf("Gia thn klash megethous %d den yparxei akoma dipla syndedemenh lista\n", nii->array[i].size_class);
		else
		{
			printf("Gia thn klash megethous %d YPARXEI dipla syndedemenh lista\n\t", nii->array[i].size_class);
			tester = nii->array[i].head;
			while(tester != NULL)
			{nodes_counted++; tester = tester->next;}
			printf("kai exei %d kombous\n", nodes_counted);
		}
	}
	printf("\n");
	int * magik2 = mymalloc(2017);
	for (i=0; i<8; i++)
	{
		nodes_counted=0;
		if(nii->array[i].head == NULL)
			printf("Gia thn klash megethous %d den yparxei akoma dipla syndedemenh lista\n", nii->array[i].size_class);
		else
		{
			printf("Gia thn klash megethous %d YPARXEI dipla syndedemenh lista\n\t", nii->array[i].size_class);
			tester = nii->array[i].head;
			while(tester != NULL)
			{nodes_counted++; tester = tester->next;}
			printf("kai exei %d kombous\n", nodes_counted);
		}
	}
	int * magik3 = mymalloc(2018);
	for (i=0; i<8; i++)
	{
		if(nii->array[i].head == NULL)
			printf("Gia thn klash megethous %d den yparxei akoma dipla syndedemenh lista\n", nii->array[i].size_class);
		else
		{
			printf("Gia thn klash megethous %d YPARXEI dipla syndedemenh lista\n\t", nii->array[i].size_class);
			tester = nii->array[i].head;
			while(tester != NULL)
			{nodes_counted++; tester = tester->next;}
			printf("kai exei %d kombous\n", nodes_counted);
		}
	}
	printf("\n");
	

	myfree(magik2);
	return 0;
}

//ELEGXOS GIA TA BITVECTORS PRIN KAI META TH MYFREE
/*int main(void)
{
	int nth_bit, i, x;
	void * magik = mymalloc(5*sizeof(int));
	unsigned hashval = hash(magik, 4093);
	hashnode * test = hash_table[hashval];
	void* temp = magik;
	i = temp;
	while (i % 4096 != 0){i-- ; temp-- ;}	//to stroggyleuoume se pollaplasio tou 4096 pros ta katw

	if (hash_table[hashval] == NULL)
		puts("klapse");
	else
	{
		while (test != NULL)
		{
			if (temp == test->pagenode->pageptr)	//einai h selida poy periexei to antikeimeno poy theloyme
			{
				nth_bit = (magik-temp)/(test->pagenode->size_class) +1; //briskoyme pio bit tou bitvector prepei na allaksei apo 1 se 0, me thn arithmish na ksekina ap to 1
				x = nth_bit/CHAR_BIT ; //h thesi toy pinaka 16 thesewn poy prepei na koitaksoume
				if(test->pagenode->bitvector[x] &  1<<(nth_bit-1))	//an dhladh to nosto bit poy afora th mymalloc poy kaname einai 1
					printf("to bit egine 1 apo th mymalloc\n");	
			}
			test = test->next;
		}
	}
	myfree(magik);
	test = hash_table[hashval];
	while (test != NULL)
		{
			if (temp == test->pagenode->pageptr)	//einai h selida poy periexei to antikeimeno poy theloyme
			{
				nth_bit = (magik-temp)/(test->pagenode->size_class) +1; //briskoyme pio bit tou bitvector prepei na allaksei apo 1 se 0, me thn arithmish na ksekina ap to 1
				x = nth_bit/CHAR_BIT ; //h thesi toy pinaka 16 thesewn poy prepei na koitaksoume
				if(test->pagenode->bitvector[x] &  1<<(nth_bit-1))	//an h free egine swsta, to parakatw mhnyma den prepei na emfanistei
					printf("to bit einai akoma 1\n");	
			}
			test = test->next;
		}
	return 0;
}*/

//DHMIOURGIA TWO-DIMENSIONAL ARRAY KAI MYFREE AUTOU
/*int main(void)
{
	 int r = 3, c = 4, i, j, count;
 
    int *arr[r];
    for (i=0; i<r; i++)
         arr[i] = (int *)mymalloc(c * sizeof(int));
 
    
    count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         arr[i][j] = ++count; 
 
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", arr[i][j]);
 
	for (i = 0; i <  r; i++)
		myfree(arr[i]);
 
	return 0;
}
*/
