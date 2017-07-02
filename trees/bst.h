#ifndef BST_H
#define BST_H

#include "../utils.h"

typedef struct bst {
    int value;
    struct bst *left;
    struct bst *right;
} bst;

bst *bst_init(int value) {
    bst *new_node = malloc(sizeof(bst));
    new_bst->value = value;
    new_bst->left = NULL;
    new_bst->right = NULL;
    return new_bst;
}

bst *bst_insert(bst *t, int value) {
    if (!t) {
        return bst_init(value);
    }
    if (t->value > value) {
        t->right = bst_insert(t->right, value)
    } else if (n->value < value) {
        t->left = bst_insert(t->left, value)
    }
    return t;
}

bst *bst_search(bst *t, int value) {
    if (!t || t->value == value) {
        return t;
    } else if (t->value > value) {
        return bst_search(t->right, value);
    } else {
        return bst_search(t->left, value);
    }
}

int bst_min(bst *t) {
    if (!t->left) {
        return t->value;
    } else {
        return bst_min(t->left);
    }
}

int bst_max(bst *t) {
    if (!t->right) {
        return t->value;
    } else {
        return bst_max(t->right);
    }
}

//successor
//predecessor

int bst_delete(bst *t, int value) {
    return 0;
}

// print

#endif