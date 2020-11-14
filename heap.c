#include <stdlib.h>

#include "heap.h"

void init_heap(Heap* h, int heapSize, int elementSize) {
    h->heapSize = heapSize;
    h->elementSize = elementSize;
    h->heap = malloc(heapSize * elementSize);
}

void destroy_heap(Heap* h) {
    for (int i=0; i<h->heapSize; i++) {
        free(h->heap[i]);
    }
    free(h);
}