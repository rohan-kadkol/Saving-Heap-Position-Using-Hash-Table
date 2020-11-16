# define INVALID_HEAP_INDEX -1

typedef struct _HashElement {
    char *airport;
    int heapIndex;
} HashElement;

void init_hash_element(HashElement *he, char airport[4]);
void init_hash_element_1(HashElement *he, char airport[4], int heapIndex);
void print_hash_element(void* e);