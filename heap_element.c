#include<stdio.h>

#include "heap_element.h"

void init_heap_element(HeapElement *he, char airport[4]) {
    he->airport = airport;
    he->dj = __INT_MAX__;
}

void init_heap_element_1(HeapElement *he, char airport[4], int dj) {
    init_heap_element(he, airport);
    he->dj = dj;
}

void print_heap_element(void* e) {
    HeapElement *he = (HeapElement*) e;
    printf("Airport %s has shortest distance %d\n", he->airport, he->dj);
}