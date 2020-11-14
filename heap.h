typedef struct _Heap {
    int heapSize;
    int elementSize;
    void** heap;
} Heap;

void init_heap(Heap* h, int heapSize, int elementSize)