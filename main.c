#include <stdio.h>
#include <stdlib.h>

#include "hash_element.h"
#include "hash_table.h"
#include "heap.h"
#include "heap_element.h"

#define HASH_TABLE_SIZE 100

int hashing_function(void* e) { return 1; }

int compare_heap_elements(void* e1, void*e2) {
    HeapElement *h1 = e1;
    HeapElement *h2 = e2;
    return h1->dj - h2->dj;
}

int main() {
    // HashTable ht;
    // init_hash_table(&ht, HASH_TABLE_SIZE, sizeof(HashElement), NULL,
    // hashing_function, print_hash_element);

    // HashElement he;
    // init_hash_element(&he, "ABC");

    // insert_into_hash_table(&ht, &he);

    // print_hash_elements(&ht);

    // destroy_hash_table(&ht);

    Heap h;
    init_heap(&h, HASH_TABLE_SIZE, sizeof(HeapElement), compare_heap_elements, print_heap_element);

    HeapElement he;
    init_heap_element(&he, "GHI");
    he.dj = 4;
    insert_into_heap(&h, &he);

    init_heap_element(&he, "JKL");
    he.dj = 7;
    insert_into_heap(&h, &he);

    init_heap_element(&he, "MNO");
    he.dj = 3;
    insert_into_heap(&h, &he);

    init_heap_element(&he, "PQR");
    he.dj = 1;
    insert_into_heap(&h, &he);

    init_heap_element(&he, "STU");
    he.dj = 10;
    insert_into_heap(&h, &he);

    init_heap_element(&he, "VQX");
    he.dj = 8;
    insert_into_heap(&h, &he);

    init_heap_element(&he, "YYZ");
    he.dj = 4;
    insert_into_heap(&h, &he);

    print_heap_elements(&h);
}