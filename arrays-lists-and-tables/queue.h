#ifndef QUEUE_H
#define QUEUE_H

#include "../utils.h"
#include "vector.h"

typedef struct queue {
    vector *v;
} queue;

queue *queue_init(int capacity) {
    queue *q = safe_malloc(sizeof(queue));
    q->v = v_init(capacity);
    return q;
}

void queue_push(queue *q, int value) {
    v_add(q->v, value);
}

int queue_pop(queue *q) {
    int retval = q->v->array[0];
    v_delete(q->v, 0);
    return retval;
}

void queue_print(queue *q) {
    v_print(q->v);
}

#endif