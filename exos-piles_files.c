#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int T;

typedef struct deque {
    T *data;
    int capacity;
    int size;
    int left;
} deque;

deque *new(int r) {
    deque *res = malloc(sizeof(deque));
    res->data = malloc(sizeof(T) * r);
    res->capacity = r;
    res->size = 0;
    res->left = 0;
    return res;
}

void add_right(deque *f, int x) {
    if (f->capacity == f->size) return;
    f->data[((f->left) + (f->size)) % f->capacity] = x;
    f->size++;
}

void add_left(deque *f, int x) {
    if (f->capacity == f->size) return;
    f->left = (f->left - 1 + f->capacity) % f->capacity;
    f->data[f->left] = x;
    f->size++;
}

int peek_right(deque *f) {
    return f->data[(f->left + f->size - 1) % f->capacity];
}

int peek_left(deque *f) {
    return f->data[f->left];
}

int main(void) {
    return 0;
}