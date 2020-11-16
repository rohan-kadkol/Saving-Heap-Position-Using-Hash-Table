#include "hash_table.h"

typedef struct _Heap {
    int heapSize;
    int elementSize;
    int currentSize;
    HashTable* hashTable;
    int (*compare)(void* e1, void* e2);
    void (*print_element)(void* e);
    void** heap;
} Heap;

void init_heap(Heap* h, int heapSize, int elementSize, HashTable* hashTable,
               int (*compare)(void* e1, void* e2),
               void (*print_element)(void* e));
void destroy_heap(Heap* h);
void swap(Heap* h, int i1, int i2);
void sift_up(Heap* h, int index);
void insert_into_heap(Heap* h, void* heapElement, void* hashElement);
void decrease_key(Heap* h, void* heapElement);
void print_heap_elements(Heap* h);