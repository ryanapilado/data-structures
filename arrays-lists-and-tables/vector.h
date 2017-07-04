#ifndef VECTOR_H
#define VECTOR_H

#include "../utils.h"

typedef struct {
    int *array;
    int n;
    int capacity;
} vector;

void v_add(vector *v, int value) {
    if (v->n == v->capacity) {
        int *new_array = safe_malloc(sizeof(int) * v->capacity * 2);
        int i;
        for (i = 0; i < v->capacity; i++) {
            new_array[i] = v->array[i];
        }
        free(v->array);
        v->array = new_array;
    }
    v->array[v->n] = value;
    v->n++;
}

void v_delete(vector *v, int index) {
    int i;
    for (i = index; i < v->n - 1; i++) {
        v->array[i] = v->array[i + 1];
    }
    v->n--;
}

void v_swap(vector *v, int i, int j) {
    int temp = v->array[i];
    v->array[i] = v->array[j];
    v->array[j] = temp;
}

void v_print(vector *v) {
    if (v->n == 0) {
        printf("EMPTY\n");
        return;
    }

    int i;
    for (i = 0; i < v->n; i++) {
        printf("%d ", v->array[i]);
    }
    printf("\n");
}

vector *v_init(int capacity) {
    vector *v = safe_malloc(sizeof(vector));
    v->n = 0;
    v->capacity = capacity;
    v->array = safe_malloc(sizeof(int) * capacity);
    return v;
}

void v_destroy(vector *v) {
    free(v->array);
    free(v);
}

#endif