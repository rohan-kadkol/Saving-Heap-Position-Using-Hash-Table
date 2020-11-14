#include <stdio.h>

#include "hash_table.h"
#include "hash_element.h"

#define HEAP_SIZE 100

int hashing_function(void* e) {
    return 1;
}

int main() {
    HashTable ht;
    init_hash_table(&ht, HEAP_SIZE, sizeof(HashElement), NULL, hashing_function, print_hash_element);

    HashElement he;
    init_hash_element(&he, "ABC");
    
    insert_into_hash_table(&ht, &he);

    // // HashElement he1;
    // peek_at_element(&ht, &he);

    // // printf("%u\n", ht);
    // // printf("%d\n", ht.size);
    // // print_elements(&ht);

    // // printf("%s\n", he.airport);
    // // printf("%d\n", he.heapIndex);

    // init_hash_element(&he, "DEF");
    // insert_into_hash_table(&ht, &he);
    // peek_at_element(&ht, &he);

    // printf("%s\n", he.airport);
    // printf("%d\n", he.heapIndex);

    print_elements(&ht);

    destroy_hash_table(&ht);
}