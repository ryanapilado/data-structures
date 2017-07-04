#ifndef STACK_H
#define STACK_H

#include "../utils.h"
#include "vector.h"

typedef struct stack {
    vector *v;
} stack;

void push(stack *s, int value) {
    v_add(s->v, value);
}

int pop(queue *q) {
    return q->v[q->v->n - 1];
}

#endif