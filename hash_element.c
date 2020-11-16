#include <stdio.h>

#include "hash_element.h"

void init_hash_element(HashElement *he, char airport[4]) {
    he->airport = airport;
    he->heapIndex = INVALID_HEAP_INDEX;
}

void init_hash_element_1(HashElement *he, char airport[4], int heapIndex) {
    init_hash_element(he, airport);
    he->heapIndex = heapIndex;
}

void print_hash_element(void* e) {
    HashElement *he = (HashElement*) e;
    printf("%s is at heap index %d\n", he->airport, he->heapIndex);
}