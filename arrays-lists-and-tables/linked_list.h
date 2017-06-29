#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../utils.h"
#include <string.h>

/* A linked list implementation. Each node can store a key, which must be an int, and
    a value as a void pointer.
*/

typedef struct ll_node {
    char *key;
    void *value;
    struct ll_node *next;
} ll_node;

typedef struct linked_list {
    ll_node *head;
} linked_list;

void ll_add(linked_list *l, char *key, void *value) {
    ll_node *new_node = safe_malloc(sizeof(ll_node));
    new_node->key = safe_malloc(sizeof(char) * strlen(key));
    memcpy(new_node->key, key, strlen(key));
    new_node->value = value;
    new_node->next = l->head;
    l->head = new_node;
}

void ll_delete(linked_list *l, int index) {
    if (index == 0) {
        l->head = l->head->next;
        return;
    }

    ll_node *curr = l->head;
    while (index > 1) {
        if (!curr->next) {
            return;
        }
        curr = curr->next;
        index--;
    }
    curr->next = curr->next->next;

}

int ll_delete_key(linked_list *l, char *key) {
    ll_node *curr = l->head;
    int ndeleted = 0;

    // case where no nodes are in list
    if (!curr) {
        return ndeleted;
    }

    // case where key to be deleted is first in list
    if (strcmp(curr->key, key) == 0) {
        l->head = curr->next;
        ndeleted++;
    }

    while (curr->next) {
        if (strcmp(curr->next->key, key) == 0) {
            curr->next = curr->next->next;
            ndeleted++;
        }
        curr = curr->next;
    }

    return ndeleted;
}

int ll_search(linked_list *l, char *key) {
    ll_node *curr = l->head;
    int i = 0;
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return i;
        }
        i++;
        curr = curr->next;
    }
    return -1;
}

void ll_print(linked_list *l) {
    ll_node *curr = l->head;
    while (curr) {
        printf("%s -> ", curr->key);
        curr = curr->next;
    }
    printf("NULL\n");
}

linked_list *ll_init() {
    linked_list *l = safe_malloc(sizeof(linked_list));
    l->head = NULL;
    return l;
}

void ll_destroy(linked_list *l) {
    ll_node *curr = l->head;
    ll_node *temp;
    while (curr) {
        temp = curr;
        curr = curr->next;
        free(temp->key);
        free(temp);
    }
    free(l);
}

#endif