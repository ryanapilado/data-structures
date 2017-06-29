#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "linked_list.h"

typedef struct hash_table {
    int size;
    int (*hash_function)(struct hash_table *h, int value);
    linked_list **table;
} hash_table;

/* Insert value into table. If value already in table, do nothing.
*/
void ht_insert(hash_table *h, int value) {
    ll_add(h->table[ h->hash_function(h, value) ], value);
}

/* Search for the value in the table and return the index of the linked_list
    list in which it is stored. If value is not in the table, return -1.
*/
int ht_search(hash_table *h, int value) {
    return ll_search(h->table[ h->hash_function(h, value) ], value);
}

/* Delete the value from the table, if it does not exist in the table,
    do nothing.
*/
void ht_delete(hash_table *h, int value) {
    ll_delete_value(h->table[ h->hash_function(h, value) ], value);
}

void ht_print(hash_table *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        printf("%d ", i);
        ll_print(h->table[i]);
    }
}

int mod_hash(hash_table *h, int value) {
    return value % h->size;
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