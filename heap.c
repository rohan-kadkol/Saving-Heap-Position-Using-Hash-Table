#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_heap(Heap* h, int heapSize, int elementSize,
               int (*compare)(void* e1, void* e2),
               void (*print_element)(void* e)) {
    h->heapSize = heapSize;
    h->elementSize = elementSize;
    h->currentSize = 0;
    h->compare = compare;
    h->print_element = print_element;
    h->heap = malloc(heapSize * elementSize);
}

void destroy_heap(Heap* h) {
    for (int i = 0; i < h->heapSize; i++) {
        free(h->heap[i]);
    }
    free(h->heap);
}

void swap(Heap* h, int i1, int i2) {
    void* temp = h->heap[i1];
    h->heap[i1] = h->heap[i2];
    h->heap[i2] = temp;
}

void sift_up(Heap* h, int index) {
    if (index < 0) {
        return;
    }

    int currentIndex = index, parentIndex;
    void *currentElement, *parentElement;
    while (currentIndex) {
        parentIndex = (currentIndex - 1) / 2;
        parentElement = h->heap[parentIndex];
        currentElement = h->heap[currentIndex];
        if (h->compare(parentElement, currentElement) > 0) {
            swap(h, parentIndex, currentIndex);
            currentIndex = parentIndex;
        } else {
            break;
        }
    }
}

void insert_into_heap(Heap* h, void* element) {
    void* heapElement = malloc(h->elementSize);
    memcpy(heapElement, element, h->elementSize);

    h->heap[h->currentSize] = heapElement;
    sift_up(h, h->currentSize);
    h->currentSize++;
}

/* Manually reduce the key of element, then pass it as a parameter.
*/
void decrease_key(Heap* h, void* element, int elementIndex) {
    memcpy(h->heap[elementIndex], element, h->elementSize);
    sift_up(h, elementIndex);
}

void print_heap_elements(Heap* h) {
    printf("<-----START----->\n");
    for (int i = 0; i < h->heapSize; i++) {
        void* element = h->heap[i];
        if (element) {
            printf("Index %d\n", i);
            h->print_element(element);
        }
    }
    printf("<-----END------->\n");
}