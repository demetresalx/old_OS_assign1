typedef struct hashnode{
	struct hashnode * next;	//epomenos hash-kombos, gia chaining se periptwsh sygkroushs
	int size_class ;	//taksh megethous antikeimenoy sto opoio anaferetai
	listnode * pagenode;	// o deikths pros ton kombo poy anaparista th selida kai exei mesa ta bitvectors ktl
}hashnode;

void insert_new_hashnode(hashnode ** , int , listnode * );	//bazei neo node sto telos ths listas

hashnode* hash_table[4093] ;	//o hash table einai enas statikos pinakas deiktwn typoy hashnode. Global kai autos

void hash_table_init();	//kanei NULL tous deiktes

unsigned hash( char *, long int  );	// h hash synarthsh
