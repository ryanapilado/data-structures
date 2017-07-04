#ifndef QUEUE_H
#define QUEUE_H

#include "../utils.h"
#include "vector.h"

typedef struct queue {
    vector *v;
} queue;

void queue_push(queue *q, int value) {
    v_add(q->v, value);
}

int queue_pop(queue *q) {
    return q->v->array[0];
}

#endif