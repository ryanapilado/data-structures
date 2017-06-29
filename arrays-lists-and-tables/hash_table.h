#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../utils.h"
#include "linked_list.h"

/* Implementation of a hash table with collision resolution by chaining.
    Keys must be an integer. Keys are hashed by mod.
*/

typedef struct hash_table {
    int size;
    int (*hash_function)(struct hash_table *h, int key);
    linked_list **table;
} hash_table;

void ht_insert(hash_table *h, int key, void *value) {
    ll_add(h->table[ h->hash_function(h, key) ], key, value);
}

int ht_search(hash_table *h, int key) {
    return ll_search(h->table[ h->hash_function(h, key) ], key);
}

void ht_delete(hash_table *h, int key) {
    ll_delete_key(h->table[ h->hash_function(h, key) ], key);
}

void ht_print(hash_table *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        printf("%d ", i);
        ll_print(h->table[i]);
    }
}

int mod_hash(hash_table *h, int key) {
    return key % h->size;
}

hash_table *ht_init(int size) {
    hash_table *h = safe_malloc(sizeof(hash_table));
    h->size = size;
    h->hash_function = mod_hash;
    h->table = safe_malloc(sizeof(void *) * size);
    int i;
    for (i = 0; i < size; i++) {
        h->table[i] = safe_malloc(sizeof(linked_list));
        ll_init(h->table[i]);
    }
    return h;
}

void ht_destroy(hash_table *h) {
    int i;
    for (i = 0; i < h->size;i ++) {
        ll_destroy(h->table[i]);
    }
    free(h->table);
}

#endif