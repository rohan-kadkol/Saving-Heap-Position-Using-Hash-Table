#include <stdio.h>
#include <stdlib.h>

#include "hash_element.h"
#include "hash_table.h"

#define HEAP_SIZE 100

int hashing_function(void* e) { return 1; }

struct ABC {
    int a;
    int b;
};

int main() {
    // HashTable ht;
    // init_hash_table(&ht, HEAP_SIZE, sizeof(HashElement), NULL,
    // hashing_function, print_hash_element);

    // HashElement he;
    // init_hash_element(&he, "ABC");

    // insert_into_hash_table(&ht, &he);

    // print_elements(&ht);

    // destroy_hash_table(&ht);

    struct ABC abc;
    abc.a = 1;
    abc.b = 2;

    printf("a=%d, b=%d\n", abc.a, abc.b);
    free(&abc);
    printf("a=%d, b=%d\n", abc.a, abc.b);

    abc.a = 3;
    abc.b = 4;

    printf("a=%d, b=%d\n", abc.a, abc.b);
}