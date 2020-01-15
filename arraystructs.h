typedef struct listnode{
	//char * bitvector;	//pinakas apo 0 kai 1 megethous iso me 4096/size_class poy deixnei thn katastash sth selida
	char bitvector[16];
	int size_class;		//klash megethous se kathe kombo
	void * pageptr;		//deikths pros thn arxh ths selidas
	struct listnode * next;
	struct listnode * prev;	//next kai prev gia dipla syndedemenh lista
}listnode;


typedef struct SizeClassCell{
	int size_class;		//klash megethous
	listnode * head;//deikths pros th dipla syndedemnh lista
}SizeClassCell;


typedef struct SizesArray{
	SizeClassCell * array; //exei mesa SizeClassCell(s)
}SizesArray;

void SizesArray_init(SizesArray ** , int );	//synarthsh arxikopoihshs/dhmiourgias ths domhs

SizesArray * SizesArray_Create();

void listnode_insert(listnode ** , int );	//synarthsh arxikopoihshs/dhmiourgias ths listas


void * GetPage(int );	//dinei selides

SizesArray * nii; //h global metablhth
