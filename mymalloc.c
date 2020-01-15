#include "arraystructs.h"
#include <stdio.h>
#include "mymalloc.h"
#include "hash.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int created=0;	//gia na kalesoume thn create mono mia fora sthn arxh

void * mymalloc(size_t cbytes)
{
	void *ptr = NULL;
	int size_class, i, bits_req,j, k, avail_place;
	double  no_of_reps;
	int found_avail =0;
	if (cbytes > 4096) //tote to megethos einai poly megalo, kanonikh malloc tha klh8ei
	{
		ptr = malloc(cbytes);
		return ptr;
	}
	else//H SOBARH PERIPTWSH
	{
		if (created==0)
		{
			nii = SizesArray_Create();	//dhmioyrgia/arxikopoihsh ths domhs
			hash_table_init();		//arxikopoihsh kai tou hashtable
			created++ ;
		}
		size_class = 32; //ksekiname apo 32 sta plaisia ths askhshs
		while(size_class <= 4096)
		{
			if (cbytes <= size_class)//se authn thn klash megethous anhkei to antikeimeno
				{cbytes = size_class;break;}
			
			size_class *= 2; 
		}
		for (i=0; i<8; i++)	//euresh swsths klashs megethous
		{
			if (nii->array[i].size_class == size_class)//brhkame to swsto i
				break;
		}
		if (nii->array[i].head == NULL)
		{
			listnode_insert(&(nii->array[i].head) , nii->array[i].size_class);//dhmiourgei kombo
			//setarei thn katallhlh thesi bitvector se 1 kai epistrefei to deikth sth selida
			nii->array[i].head->bitvector[0] |= 1  ; //o bitvector ola 0 arxika, tha kanei 1 thn prwti thesi
			ptr = nii->array[i].head->pageptr ;	//epistrefei deikth sth selida
			ptr++;	//auto anebazei kata 1 thn timh tou deikth wste o xrhsths na mporei na grapsei panw sth desmeumenh mnhmh xwris na xalasei thn 1h dieu8unsh h opoia tha xrhsimopoieitai gia na entopistei apo th myfree
			
			
		}
		else //yparxei kefalh
		{
			bits_req = 4096/size_class ;	//posa bits tha elegksoume
			no_of_reps = (double)bits_req/(double)CHAR_BIT ;	//poses theseis tou bitvector tha koitaksoume
			no_of_reps = ceil(no_of_reps);
			
			for (j=0; j<no_of_reps ; j++)
			{
				//printf("no of reps is %lf\n", no_of_reps);
				for (k=0; k< CHAR_BIT ; k++)
				{
					if ((j*(CHAR_BIT) + k) >= bits_req ) { j = no_of_reps; break; }//gia na mhn koitaksoume allo

					if(nii->array[i].head->bitvector[j] & (1<<k))
						{/*to bit einai 1 poy shmainei kateilhmmenh thesi*/}
					else
						{
							found_avail =1; //brhkame diathesimh
							//printf("ebala sto idio\n");
							avail_place = j*(CHAR_BIT) + k;
							ptr = nii->array[i].head->pageptr + (size_class*avail_place) ;//gia na deiksei sth swsth thesi mesa sth selida
							nii->array[i].head->bitvector[j] |= 1<<k ; //to k-osto bit prepei na ginei 1 afou pleon einai kateilhmmeno
							
							j = no_of_reps ; //gia na stamathsei h ekswterikh for
							break; //gia na stamathsei auth h for
						}
					
				}
				
			}
			if (found_avail ==0) //de brethike thesi, ftiaxnoyme neo komvo (oi eisagwges ksekinane panta ap thn arxh ara arkei na koitame to head, oi epomenoi komboi tha einai gematoi an yparxoun)
			{
				//printf("nea kefalh kai to bala ekei\n");
				listnode_insert(&(nii->array[i].head) , nii->array[i].size_class);//dhmiourgei kombo
				nii->array[i].head->bitvector[0] |= 1  ; //o bitvector ola 0 arxika, tha kanei 1 thn prwti thesi
				ptr = nii->array[i].head->pageptr ;	//epistrefei deikth sth selida
				ptr++;	//auto anebazei kata 1 thn timh tou deikth wste o xrhsths na mporei na grapsei panw sth desmeumenh mnhmh xwris na xalasei thn 1h dieu8unsh h opoia tha xrhsimopoieitai gia na entopistei apo th myfree
		
			}
		}
		
	}
	
	return ptr;
}

void myfree(void * ptr)
{
	int i, j, x, nth_bit;
	int found = 0;
	void* temp = ptr;
	i = temp;
	while (i % 4096 != 0){i-- ; temp-- ;}	//to stroggyleuoume se pollaplasio tou 4096 pros ta katw
	//printf("portes : %d and true %d\n", temp, ptr);
	unsigned HA;
	HA = hash(temp, 4093);
	hashnode * test = hash_table[HA];
	while (test != NULL)
	{
		if (temp == test->pagenode->pageptr)	//einai h selida poy periexei to antikeimeno poy theloyme
		{
			found =1;
			nth_bit = (ptr-temp)/(test->pagenode->size_class) +1; //briskoyme pio bit tou bitvector prepei na allaksei apo 1 se 0, me thn arithmish na ksekina ap to 1
			x = nth_bit/CHAR_BIT ; //h thesi toy pinaka 16 thesewn poy prepei na koitaksoume
			test->pagenode->bitvector[x] ^= 1<<(nth_bit-1);	//kanei flip to bit poy theloyme, twra egine 0 wste na einai pali diathesimo
		}
		test = test->next;
	}
	if (found == 0)
		free(ptr);	//den einai sto diko mas allocator, ara kanonikh free toy systhmatos
}



