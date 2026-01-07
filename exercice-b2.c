#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void incremente(int *p) {
    *p = *p + 1;
}

int plus_petit1(int x, int y) {
    if (x <= y) return x;
    return y;
}

void f1(int *px, int *py) {
    incremente(plus_petit1(*px, *py));
}

int *plus_petit2(int x, int y) {
    if (x <= y) return &x;
    return &y;
}

void f2(int *px, int *py) {
    incremente(plus_petit2(*px, *py));
}

int *plus_petit3(int x, int y) {
    if (x <= y) return &x;
    return &y;
}

void f3(int *x, int *y) {
    if (*x <= *y) return x;
    return y;
}

int *plus_petit4(int *x, int *y) {
    int a = *x;
    int b = *y;

    if (a <= b) return &a;
    return &b;
}

void f4(int *px, int *py) {
    plus_petit4(px, py);
}


int main(void) {

    int x = 4;
    int y = 3;
    printf("x = %d, y %d\n", x, y);
    f3(&x, &y);
    printf("x = %d, y %d\n", x, y);
    return 0;
}



