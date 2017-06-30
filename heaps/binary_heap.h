#include "../utils.h"
#include "../arrays-lists-and-tables/vector.h"

typedef struct binary_heap {
    vector *v;
    int (*f)(int a, int b);
} binary_heap;

enum order{
    MIN,
    MAX
};

int lesser(int a, int b) {
    return a < b;
}

int greater(int a, int b) {
    return a > b;
}

/* Heapify the i-th element in the heap. Not the element at index i!
*/
void heapify(binary_heap *h, int i) {
    vector *v = h->v;
    int max = i;
    int left = i * 2;
    int right = i * 2 + 1;
    if (left <= v->n && h->f(v->array[left - 1], v->array[i - 1])) {
        max = left;
    }
    if (right <= v->n && h->f(v->array[right - 1], v->array[max - 1])) {
        max = right;
    }
    if (max != i) {
        v_swap(v, max - 1, i - 1);
        heapify(h, max);
    }
}

void heap_build(binary_heap *h)  {
    vector *v = h->v;
    int i;
    for (i = v->n / 2 - 1; i >= 0; i++) {
        heapify(h, i);
    }
}

int heap_get(binary_heap *h) {
    vector *v = h->v;
    return v->array[0];
}

int heap_extract(binary_heap *h) {
    vector *v = h->v;
    int min = v->array[0];
    v->array[0] = v->array[v->n - 1];
    heapify(h, 0);
    return min;
}

void bubble_up(binary_heap *h, int i) {
    vector *v = h->v;
    int parent = i / 2;
    if (i == 1) {
        return;
    }
    if (h->f(v->array[parent - 1], v->array[i - 1])) {
        v_swap(v, i - 1, parent - 1);
        bubble_up(h, parent);
    }
}

void heap_insert(binary_heap *h, int k) {
    vector *v = h->v;
    v_add(v, k);
    bubble_up(h, v->n);
}

void heap_print(binary_heap *h) {
    return;
}

binary_heap *heap_init(int capacity, int order) {
    binary_heap *h = safe_malloc(sizeof(binary_heap));
    h->v = v_init(capacity);
    if (order == MIN) {
        h->f = &greater;
    } else {
        h->f = &lesser;
    }
    return h;
}