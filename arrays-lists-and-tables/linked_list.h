#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../utils.h"

typedef struct ll_node {
    int value;
    struct ll_node *next;
} ll_node;

typedef struct linked_list {
    ll_node *head;
} linked_list;

void ll_add(linked_list *l, int value) {
    ll_node *new_node = safe_malloc(sizeof(ll_node));
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

/* Delete the first occurence of value in the list.
*/
void ll_delete_value(linked_list *l, int value) {
    ll_node *curr = l->head;

    // case where no nodes are in list
    if (!curr) {
        return;
    }

    // case where value to be deleted is first in list
    if (curr->value == value) {
        l->head = curr->next;
        return;
    }

    while (curr->next) {
        if (curr->next->value == value) {
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
}

/* Check if value exists in the list and return its index if it does,
    otherwise return -1;
*/
int ll_search(linked_list *l, int value) {
    ll_node *curr = l->head;
    int i = 0;
    while (curr) {
        if (curr->value == value) {
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
        printf("%d -> ", curr->value);
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
        free(temp);
    }
    free(l);
}

#endif