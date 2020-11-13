typedef struct _HashTable {
    int size;
    int elementSize;
    int (*compare_elements)(void* e1, void* e2);
    void **hashTable;
} HashTable;

void init_hash_table(HashTable* ht, int size, int elementSize,
                     int (*compare_elements)(void* e1, void* e2));
void destroy_hash_table(HashTable* ht);