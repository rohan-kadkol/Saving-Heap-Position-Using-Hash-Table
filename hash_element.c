#include "hash_element.h"

void init_hash_element(HashElement *he, char airport[4]) {
    he->airport = airport;
    he->heapIndex = INVALID_HEAP_INDEX;
}