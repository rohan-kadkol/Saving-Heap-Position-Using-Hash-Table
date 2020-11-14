#include "hash_table.h"
#include "hash_element.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init_hash_table(HashTable* ht, int size, int elementSize,
                     int (*compare_elements)(void* e1, void* e2),
                     int (*hashing_function)(void* e),
                     void (*print_element)(void* e)) {
    ht->size = size;
    ht->elementSize = elementSize;
    ht->compare_elements = compare_elements;
    ht->hashing_function = hashing_function;
    ht->hashTable = malloc(size * elementSize);
}

void destroy_hash_table(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        free(ht->hashTable[i]);
    }
    free(ht->hashTable);
}

void insert_into_hash_table(HashTable* ht, void* element) {
    printf("1: %u\n", ht);
    printf("%d\n", ht->size);
    void* hashElement = malloc(ht->size);
    printf("2: %u\n", ht);
    printf("%d\n", ht->size);
    memcpy(hashElement, element, ht->elementSize);
    printf("3: %u\n", ht);
    printf("%d\n", ht->size);

    int hashIndex = ht->hashing_function(element);
    printf("4: %u\n", ht);
    printf("%d\n", ht->size);
    printf("^^%u\n", ht->hashTable[hashIndex]);
    // printf("^%d\n", ((HashElement*)ht->hashTable[hashIndex])->airport);
    ht->hashTable[hashIndex] = hashElement;
    printf("5: %u\n", ht);
    printf("%d\n", ht->size);
    printf("^^%u\n", ht->hashTable[hashIndex]);
    printf("hashElement: %u\n", hashElement);
    printf("^%s\n", ((HashElement*)ht->hashTable[hashIndex])->airport);
}

void peek_at_element(HashTable* ht, void* element) {
    printf("6: %u\n", ht);
    printf("%d\n", ht->size);
    int hashIndex = ht->hashing_function(element);
    printf("HASHING INDEX: %d\n", hashIndex);
    printf("7: %u\n", ht);
    printf("%d\n", ht->size);
    void* hashElement = ht->hashTable[hashIndex];

    printf("*hashElement: %u\n", hashElement);
    printf("*^%s\n", ((HashElement*)ht->hashTable[hashIndex])->airport);

    printf("8: %u\n", ht);
    printf("%d\n", ht->size);
    memcpy(element, hashElement, ht->elementSize);
    printf("9: %u\n", ht);
    printf("%d\n", ht->size);
}

void print_elements(HashTable* ht) {
    printf("ht->size = %d\n", ht->size);
    for (int i = 0; i < ht->size; i++) {
        printf("Index %d", i);
        ht->print_element(ht->hashTable[i]); 
    }
}