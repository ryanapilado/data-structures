#ifndef UTILS_H
#define UTILS_H

void *safe_malloc(size_t size) {
    void *p = malloc(size);
    if (!p) {
        perror("malloc");
        exit(1);
    }
    return p;
}

#endif