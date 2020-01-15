#include "arraystructs.h"
#include <stdio.h>
#include "mymalloc.h"
#include "hash.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>

SizesArray * SizesArray_Create()
{
	SizesArray * ichi = NULL;
	SizesArray_init(&ichi, 32);
	return ichi;
}

void SizesArray_init(SizesArray ** stru, int minsizeclass)
{
	*stru = malloc(sizeof(SizesArray)); //dhmiourgia ths domhs
	(*stru)->array = malloc(8*sizeof(SizeClassCell)); //8 theseis, mia gia kathe megethos;
	int i;
	(*stru)->array[0].size_class = minsizeclass;
	for (i=1; i<8; i++)
	{
		(*stru)->array[i].size_class = ((*stru)->array[i-1].size_class )*2;
		(*stru)->array[i].head = NULL; //arxikopoihsh dipla syndedemenwn listwn
	}
	
	
}

void listnode_insert(listnode ** lisnod, int classsize)//eisagwgh kainourgiou kombou sth dipla syndedemnh lista, se periptwsh neas selidas
{
	unsigned HA;	//gia th hash function
	if(*lisnod == NULL)	//den yparxei allh domh mprosta, th dhmiourgoume
	{
		*lisnod = malloc(sizeof(listnode)); //xwros gia ton komvo
		(*lisnod)->size_class = classsize;
		
		(*lisnod)->pageptr = GetPage(1); 	//nea selida kai deixnoyme sthn arxh ths
		
		for (int i=0; i< 16; i++)
		{
			(*lisnod)->bitvector[i] = 0;	//arxika ola diathesima sth selida, ara 0 se kathe thesi tou bit vector
		}
		(*lisnod)->next = NULL;
		(*lisnod)->prev = NULL; //prev kai next NULL, einai h kefalh xwris epomeno afou prin htan adeia h lista
			
		HA = hash((*lisnod)->pageptr, 4093);	//kanoyme hash th selida
		insert_new_hashnode(&(hash_table[HA]), classsize, *lisnod);	//pername ston hashtable
	}
	else//yparxei allos kombos, eisagwgh sthn arxh
	{
		listnode * newnode = malloc(sizeof(listnode));
		newnode->size_class = classsize;
		
		newnode->pageptr = GetPage(0);	//nea selida kai deixnoyme sthn arxh ths
		
		for (int i=0; i< 16; i++)
		{
			newnode->bitvector[i] = 0;	//arxika ola diathesima sth selida, ara 0 se kathe thesi tou bit vector
		}
		newnode->prev = NULL;
		newnode->next = *lisnod;
		(*lisnod)->prev = newnode;
		*lisnod = newnode;
			
		HA = hash((*lisnod)->pageptr, 4093);	//kanoyme hash th selida
		insert_new_hashnode(&(hash_table[HA]), classsize, *lisnod);	//pername ston hashtable
	}
}



void * GetPage(int loafing)
{
	long int i;
	static void* cur;
	static void* end;
	if (cur == end)	//otan auto to orisma perna me timh 1 exoume nea malloc tou enos MB, otan den einai 1 synexizoume
	{	
		void *loaf = malloc(1024*1024);
		cur = loaf;
		end = loaf+(1024*1024);
		i = cur;
		while((i % 4096) !=0)	//mexri na broume to prwto pollaplasio tou 4096 apo thn arxh ths desmeumenhs mnhmhs
			{cur++;i++;}
		
		i = end;
		while((i % 4096) !=0) ////mexri na broume to prwto pollaplasio tou 4096 apo to telos ths desmeumenhs mnhmhs
			{end--;i--;}
		
		//printf("%d %d %d\n", loaf, cur, end);
		void * cur2 = cur;
		cur += 4096; //giati phrame mia selida gia na thn epistrepsoume
		return cur2;
	}
	else	//loafing is 0 or anything else
	{
		void * cur2 = cur;
		cur += 4096;	//giati phrame mia selida gia na thn epistrepsoyme
		return cur2;
	}
	
}


