#ifndef QUEUE_H
#define QUEUE_H

#include "../utils.h"
#include "vector.h"

typedef struct queue {
    vector *v;
} queue;

void push(queue *q, int value) {
    v_add(q->v, value);
}

int pop(queue *q) {
    return q->v[0];
}

#endif