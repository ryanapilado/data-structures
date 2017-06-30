#include "../utils.h"
#include "../arrays-lists-and-tables/vector.h"

typedef struct binary_heap {
    vector *v;
} binary_heap;

void min_heapify(binary_heap *h, int i) {
    vector *v = h->v;
    int max = i;
    int left = i * 2;
    int right = i * 2 + 1;
    if (left <= v->n && v->array[left - 1] < v->array[i - 1]) {
        max = left;
    }
    if (right <= v->n && v->array[right - 1] < v->array[max - 1]) {
        max = right;
    }
    if (max != i) {
        v->array[i - 1] = v->array[max - 1];
        v->array[max - 1] = v->array[i - 1];
        min_heapify(h, max);
    }
}

void heap_build_min(binary_heap *h) {
    vector *v = h->v;
    int i;
    for (i = v->n / 2 - 1; i >= 0; i++) {
        min_heapify(h, i);
    }
}

int heap_get_min(binary_heap *h) {
    vector *v = h->v;
    return v->array[0];
}

int heap_extract_min(binary_heap *h) {
    vector *v = h->v;
    int min = v->array[0];
    v->array[0] = v->array[v->n - 1];
    min_heapify(h, 0);
    return min;
}

void heap_insert(binary_heap *h, int k) {
    vector *v = h->v;
    v_add(v, k);
    min_heapify(h, v->n - 1);
}

binary_heap *heap_init(int capacity) {
    binary_heap *h = safe_malloc(sizeof(binary_heap));
    h->v = v_init(capacity);
    return h;
}