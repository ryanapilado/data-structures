#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "linked_list.h"

typedef struct hash_table {
    int size;
    int (*hash_function)(struct hash_table *h, int value);
    linked_list *table;
} hash_table;

/* Insert value into table. If value already in table, do nothing.
*/
void ht_insert(hash_table *h, int value) {
    ll_add(&h->table[ h->hash_function(h, value) ], value);
}

/* Search for the value in the table and return the index of the linked_list
    list in which it is stored. If value is not in the table, return -1.
*/
int ht_search(hash_table *h, int value) {
    return ll_search(&h->table[ h->hash_function(h, value) ], value);
}

/* Delete the value from the table, if it does not exist in the table,
    do nothing.
*/
void ht_delete(hash_table *h, int value) {
    ll_delete_value(&h->table[ h->hash_function(h, value) ], value);
}

/* Print out the contents of the table.
*/
void ht_print(hash_table *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        printf("%d ", i);
        ll_print(&h->table[i]);
    }
}

/* Hash an integer value.
*/
int mod_hash(hash_table *h, int value) {
    return value % h->size;
}

/* Initialize a hash table.
*/
void ht_init(hash_table *h, int size) {
    h->size = size;
    h->hash_function = mod_hash;
    h->table = malloc(sizeof(linked_list) * size);
    int i;
    for (i = 0; i < size; i++) {
        ll_init(&h->table[i]);
    }
}

#endif