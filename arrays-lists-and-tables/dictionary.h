#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "../utils.h"
#include "hash_table.h"

/* A dictionary implementation for storing key/value pairs. Both keys and
    values must be strings. Enforces exclusivity.
*/

typedef struct dictionary {
    hash_table *h;
} dictionary;

void dict_insert(dictionary *d, char *key, char *value) {
    int hashval = ascii_sum(key);
    if (ht_search(d->h, hashval)) {
        // delete
    }
    ht_insert(d->h, hashval, value);
}

void dict_delete(char *key) {
    return;
}

string *dict_search(char *key) {
    return NULL;
}

int ascii_sum(char *s) {
    int len = strlen(s);
    int sum = 0;
    int i = 0;
    for (i = 0; i < len; i++) {
        sum += s[i];
    }
    return sum;
}

dictionary *dictionary_init(int size) {
    dictionary *d = malloc(sizeof(dictionary));
    d->h = hash_table_init(size);
}

void dict_destroy(dictionary *d) {
    // free all strings in hash table
    ht_destroy(d->h);
    free(d);
}

#endif