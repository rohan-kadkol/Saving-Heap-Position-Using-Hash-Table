# define INVALID_HEAP_INDEX -1

typedef struct _HashElement {
    char *airport;
    int heapIndex;
} HashElement;

void init_hash_element(HashElement *he, char airport[4]);