#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

void init_hash_table(HashTable* ht, int size, int elementSize,
                     int (*compare_elements)(void* e1, void* e2),
                     int (*hashing_function)(void *e)) {
    ht->size = size;
    ht->elementSize = elementSize;
    ht->compare_elements = compare_elements;
    ht->hashing_function = hashing_function;
    ht->hashTable = malloc(size*elementSize);
}

void destroy_hash_table(HashTable* ht) {
    for (int i=0; i<ht->size; i++) {
        free(ht->hashTable[i]);
    }
    free(ht->hashTable);
}

void insert_into_hash_table(HashTable *ht, void* element) {
    void *hashElement = malloc(ht->size);
    memcpy(hashElement, element, ht->elementSize);

    int hashIndex = ht->hashing_function(element);
    ht->hashTable[hashIndex] = hashElement;
}

void peek_at_element(HashTable *ht, void* he) {
    int hashIndex = ht->hashing_function(he);
    void *hashElement = ht->hashTable[hashIndex];
    memcpy(he, hashElement, ht->size);
}