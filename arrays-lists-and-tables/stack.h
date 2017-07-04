#ifndef STACK_H
#define STACK_H

#include "../utils.h"
#include "vector.h"

typedef struct stack {
    vector *v;
} stack;

stack *stack_init(int capacity) {
    stack *s = safe_malloc(sizeof(stack));
    s->v = v_init(capacity);
    return s;
}

void stack_push(stack *s, int value) {
    v_add(s->v, value);
}

int stack_pop(stack *q) {
    int retval = q->v->array[q->v->n - 1];
    v_delete(q->v, q->v->n - 1);
    return retval;
}

void stack_print(stack *s) {
    v_print(s->v);
}

#endif