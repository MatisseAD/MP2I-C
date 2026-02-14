#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int binary_dichotomy(int a[], int n, int value) {
    int lo = 0;
    int hi = n;

    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        printf("lo: %d, hi: %d, mid: %d\n", lo, hi, mid);
        if (a[mid] > value) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (a[lo] == value) {
        return lo;
    } else {
        return -1;
    }
}

int main(void) {

    int t[] = {0, 1, 1, 2, 3, 35, 8};
    int v = 3;

    binary_dichotomy(t, 7, v);

    printf("Index of %d is: %d\n", v, binary_dichotomy(t, 7, v));

    return 0;
}