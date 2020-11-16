#include <stdio.h>
#include <stdlib.h>

#include "hash_element.h"
// #include "hash_table.h"
#include "heap.h"
#include "heap_element.h"

#define HASH_TABLE_SIZE 1000

int hashing_function(void* e) {
    HashElement *he = (HashElement*) e;
    char* airport = he->airport;

    int p0 = (int)airport[0] - 'A'+ 1;
    int p1 = (int)airport[1] - 'A'+ 1;
    int p2 = (int)airport[2] - 'A'+ 1;

    int p3 = p0 * 467 * 467 + p1 * 467 + p2;

    int p4 = p3 % 7193;

    return p4 % 1000;
}

int compare_heap_elements(void* e1, void* e2) {
    HeapElement* h1 = e1;
    HeapElement* h2 = e2;
    return h1->dj - h2->dj;
}

int main() {
    HashTable ht;
    init_hash_table(&ht, HASH_TABLE_SIZE, sizeof(HashElement), NULL,
                    hashing_function, print_hash_element);

    // HashElement he;
    // init_hash_element(&he, "ABC");

    // insert_into_hash_table(&ht, &he);

    // print_hash_elements(&ht);

    // destroy_hash_table(&ht);

    Heap h;
    init_heap(&h, HASH_TABLE_SIZE, sizeof(HeapElement), &ht,
              compare_heap_elements, print_heap_element);

    HeapElement heapElement;
    HashElement hashElement;

    init_heap_element_1(&heapElement, "GHI", 4);
    init_hash_element_1(&hashElement, heapElement.airport, h.currentSize);
    insert_into_heap(&h, &heapElement, &hashElement);

    init_heap_element_1(&heapElement, "JKL", 7);
    init_hash_element_1(&hashElement, heapElement.airport, h.currentSize);
    insert_into_heap(&h, &heapElement, &hashElement);

    init_heap_element_1(&heapElement, "MNO", 3);
    init_hash_element_1(&hashElement, heapElement.airport, h.currentSize);
    insert_into_heap(&h, &heapElement, &hashElement);

    init_heap_element_1(&heapElement, "PQR", 1);
    init_hash_element_1(&hashElement, heapElement.airport, h.currentSize);
    insert_into_heap(&h, &heapElement, &hashElement);

    init_heap_element_1(&heapElement, "STU", 10);
    init_hash_element_1(&hashElement, heapElement.airport, h.currentSize);
    insert_into_heap(&h, &heapElement, &hashElement);

    init_heap_element_1(&heapElement, "VQX", 8);
    init_hash_element_1(&hashElement, heapElement.airport, h.currentSize);
    insert_into_heap(&h, &heapElement, &hashElement);

    init_heap_element_1(&heapElement, "YYZ", 4);
    init_hash_element_1(&hashElement, heapElement.airport, h.currentSize);
    insert_into_heap(&h, &heapElement, &hashElement);

    init_heap_element_1(&heapElement, "NUY", 100);
    init_hash_element_1(&hashElement, heapElement.airport, h.currentSize);
    insert_into_heap(&h, &heapElement, &hashElement);

    print_heap_elements(&h);
    print_hash_elements(&ht);

    init_heap_element_1(&heapElement, "STU", 2);
    decrease_key(&h, &heapElement);

    init_heap_element_1(&heapElement, "NUY", 1);
    decrease_key(&h, &heapElement);

    print_heap_elements(&h);
    print_hash_elements(&ht);
}