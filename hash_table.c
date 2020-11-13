#include <stdlib.h>

#include "hash_table.h"

void init_hash_table(HashTable* ht, int size, int elementSize,
                     int (*compare_elements)(void* e1, void* e2)) {
    ht->size = size;
    ht->elementSize = elementSize;
    ht->compare_elements = compare_elements;
    ht->hashTable = malloc(size*elementSize);
}

void destroy_hash_table(HashTable* ht) {
    for (int i=0; i<ht->size; i++) {
        free(ht->hashTable[i]);
    }
    free(ht->hashTable);
}