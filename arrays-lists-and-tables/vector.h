#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int *array;
    int n;
    int capacity;
} vector;

void vector_add(vector *v, int value) {
    if (v->n == v->capacity) {
        int *new_array = malloc(sizeof(int) * v->capacity * 2);
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

void vector_delete(vector *v, int index) {
    int i;
    for (i = index; i < v->n - 1; i++) {
        v->array[i] = v->array[i + 1];
    }
    v->n--;
}

void vector_print(vector *v) {
    int i;
    for (i = 0; i < v->n; i++) {
        printf("%d ", v->array[i]);
    }
    printf("\n");
}

void vector_init(vector *v, int capacity) {
    v->n = 0;
    v->capacity = capacity;
    v->array = malloc(sizeof(int) * capacity);
}

#endif