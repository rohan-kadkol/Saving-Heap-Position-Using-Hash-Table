#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "hash_element.h"

void init_hash_table(HashTable* ht, int tableSize, int elementSize,
                     int (*compare_elements)(void* e1, void* e2),
                     int (*hashing_function)(void* e),
                     void (*print_element)(void* e)) {
    ht->tableSize = tableSize;
    ht->elementSize = elementSize;
    ht->compare_elements = compare_elements;
    ht->hashing_function = hashing_function;
    ht->print_element = print_element;
    ht->hashTable = malloc(tableSize * elementSize);
}

/* Note: It only destroys all the elements that were malloc'ed (memcpy). You
 * need to call free(ht) to free the actual HashTable object
 */
void destroy_hash_table(HashTable* ht) {
    for (int i = 0; i < ht->tableSize; i++) {
        free(ht->hashTable[i]);
    }
    free(ht->hashTable);
}

void insert_into_hash_table(HashTable* ht, void* element) {
    void* hashElement = malloc(ht->elementSize);
    memcpy(hashElement, element, ht->elementSize);

    int hashIndex = ht->hashing_function(element);
    ht->hashTable[hashIndex] = hashElement;
}

void peek_at_element(HashTable* ht, void* element) {
    int hashIndex = ht->hashing_function(element);
    void* hashElement = ht->hashTable[hashIndex];
    memcpy(element, hashElement, ht->elementSize);
}

void print_hash_elements(HashTable* ht) {
    printf("<-----START----->\n");
    for (int i = 0; i < ht->tableSize; i++) {
        void* element = ht->hashTable[i];
        if (element) {
            printf("Index %d\n", i);
            ht->print_element(element);
        }
    }
    printf("<-----END------->\n");
}