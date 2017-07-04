#ifndef STACK_H
#define STACK_H

#include "../utils.h"
#include "vector.h"

typedef struct stack {
    vector *v;
} stack;

void stack_push(stack *s, int value) {
    v_add(s->v, value);
}

int stack_pop(stack *q) {
    return q->v->array[q->v->n - 1];
}

#endif