typedef struct _HeapElement {
    char *airport;    
    int dj;
} HeapElement;

void init_heap_element(HeapElement *he, char airport[4]);
void print_heap_element(void* e);