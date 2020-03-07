#include <sys/mman.h>

typedef struct __mmalloc_t
{
	int size;
	int magicNumber;
	double padding;
} mmalloc_t;

typedef struct __mmfree_t
{
	int size;
	__mmfree_t* next;
} mmfree_t;

mmfree_t* head;

void* mem_manager_malloc(int size);
void mem_manager_free(void* ptr);
//traverse the free space list starting from the head, printing out info (for debugging)
void traverse_free_list(); 
void init_mem(int free_space_size);


//called by malloc
//find a free space chunk large enough for the requested allocation
//obtain some memory from that chunk
?? locate_split(??);

//called by free
//locate the freed memory insert position so free space nodes are sorted by address
?? find_sorted_location(??);

void* mem_manager_malloc(int size) {
	
	
	
}


void mem_manager_free(void* ptr){
	
}

void init_mem(int free_space_size){
	//initialize a space of memory to break up.
    head = mmap(NULL,free_space_size,PROT_READ | PROT_WRITE,MAP_ANON | MAP_PRIVATE, -1, 0);
	
    //16 in header have 4080 left EACH TIME A MALLOC OCCURS THERE WILL BE 16 BYTES OF OVERHEAD. if you have 3000 left and malloc(14) then the heap has 2970 left (14+16).
    head->size = free_space_size - sizeof(head); 
    head->next = NULL;
	
}