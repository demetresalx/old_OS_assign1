#include "arraystructs.h"
#include <stdio.h>
#include "mymalloc.h"
#include "hash.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>

unsigned hash(char *str, long int size_of_table) {
        unsigned hash = 5381 ;
        int c;

        while ((c = *str++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash % size_of_table;
}

void hash_table_init()
{
	int i;
	for(i=0; i<4093; i++)
		hash_table[i] = NULL ;
}

void insert_new_hashnode(hashnode ** nod, int szclass, listnode * pgnode)
{
	if(*nod == NULL)	//dhmiourgia
	{
		*nod = malloc(sizeof(hashnode));
		(*nod)->size_class = szclass;
		(*nod)->pagenode = pgnode;
		(*nod)->next = NULL;
		
	}
	else	//exoume enan h perissoterous kombous, klassikh methodologia eisagwghs sto telos
	{
		hashnode* newnod = malloc(sizeof(hashnode));
		newnod->size_class = szclass;
		newnod->pagenode = pgnode;
		newnod->next = NULL;
		hashnode * temp = *nod;
		while( temp->next != NULL)
			temp = temp->next;

		temp->next = newnod;
		
	}
}
