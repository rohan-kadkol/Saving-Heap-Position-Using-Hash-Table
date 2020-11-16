#include "heap.h"
#include "heap_element.h"
#include "hash_element.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_heap(Heap* h, int heapSize, int elementSize, HashTable* hashTable,
               int (*compare)(void* e1, void* e2),
               void (*print_element)(void* e)) {
    h->heapSize = heapSize;
    h->elementSize = elementSize;
    h->currentSize = 0;
    h->hashTable = hashTable;
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

    HeapElement *heapElement1 = h->heap[i1];
    HeapElement *heapElement2 = h->heap[i2];

    HashElement hashElement1;
    HashElement hashElement2;
    init_hash_element(&hashElement1, heapElement1->airport);
    init_hash_element(&hashElement2, heapElement2->airport);
    peek_at_element(h->hashTable, &hashElement1);
    peek_at_element(h->hashTable, &hashElement2);
    hashElement1.heapIndex = i1;
    hashElement2.heapIndex = i2;
    update_hash_table_element(h->hashTable, &hashElement1);
    update_hash_table_element(h->hashTable, &hashElement2);
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

void insert_into_heap(Heap* h, void* heapElement, void* hashElement) {
    insert_into_hash_table(h->hashTable, hashElement);
    
    void* heapElementCopy = malloc(h->elementSize);
    memcpy(heapElementCopy, heapElement, h->elementSize);

    h->heap[h->currentSize] = heapElementCopy;
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