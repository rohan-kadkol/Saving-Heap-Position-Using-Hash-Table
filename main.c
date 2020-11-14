#include <stdio.h>

#include "hash_table.h"
#include "hash_element.h"

#define HEAP_SIZE 100

int hashing_function(void* e) {
    return 1;
}

int main() {
    HashTable ht;
    printf("%u\n", &ht);
    printf("%d\n", ht.size);
    printf("%d\n", ht.elementSize);
    init_hash_table(&ht, HEAP_SIZE, sizeof(HashElement), NULL, hashing_function, print_hash_element);
    printf("%u\n", &ht);
    printf("%d\n", ht.size);
    printf("%d\n", ht.elementSize);

    HashElement he;
    init_hash_element(&he, "ABC");
    he.heapIndex = 1;
    
    insert_into_hash_table(&ht, &he);

    HashElement he1;
    // // printf("%u\n", he1);
    // // printf("%s\n", he1.airport);
    // // printf("%d\n", he1.heapIndex);
    peek_at_element(&ht, &he1);

    // printf("%u\n", ht);
    // printf("%d\n", ht.size);
    // print_elements(&ht);

    // // printf("%u\n", he1);
    // // printf("%s\n", he1.airport);
    // // printf("%d\n", he1.heapIndex);

    destroy_hash_table(&ht);
}