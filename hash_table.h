typedef struct _HashTable {
    int size;
    int elementSize;
    int (*compare_elements)(void* e1, void* e2);
    int (*hashing_function)(void* e);
    void **hashTable;
} HashTable;

void init_hash_table(HashTable* ht, int size, int elementSize,
                     int (*compare_elements)(void* e1, void* e2),
                     int (*hashing_function)(void *e));
void destroy_hash_table(HashTable* ht);
void insert_into_hash_table(HashTable *ht, void* element);
void peek_at_element(HashTable *ht, void* he);