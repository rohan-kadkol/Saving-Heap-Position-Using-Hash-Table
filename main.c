#include <stdio.h>

#include "hash_table.h"
#include "hash_element.h"

#define HEAP_SIZE 100

int main() {
    HashTable ht;
    init_hash_table(&ht, HEAP_SIZE, sizeof(HashElement), NULL);
    destroy_hash_table(&ht);
}