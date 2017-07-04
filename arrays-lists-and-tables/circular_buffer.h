#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include "../utils.h"

typedef struct circular_buffer {
    int *buffer;
    int capacity;
    int n;
    int first;
    int last;
} circular_buffer;

circular_buffer *init_cb(int capacity) {
    circular_buffer *cb = safe_malloc(sizeof(circular_buffer));

    cb->buffer = safe_malloc(sizeof(int) * capacity);
    cb->capacity = capacity;
    cb->n = 0;
    cb->first = 0;
    cb->last = 0;

    return cb;
}

int cb_push(circular_buffer *cb, int value) {
    if (cb->n == cb->capacity) {
        return 0;
    }

    cb->buffer[cb->last] = value;
    cb->n++;
    cb->last++;
    if (cb->last == cb->capacity) {
        cb->last = 0;
    }
    return 0;
}

int cb_pop(circular_buffer *cb) {
    if (cb->n == 0) {
        return 0;
    }

    int retval = cb->buffer[cb->first];
    cb->n--;
    cb->first++;
    if (cb->first == cb->capacity) {
        cb->first = 0;
    }
    return retval;
}


#endif