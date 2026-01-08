#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool is_sorted(int a[], int n) {
    int i = 0;

    while (i+1 < n) {
        if (a[i+1]<a[i]) {
            return false;
        }
        i++;
    }

    return true;

}

void swap(int a[], int i, int j) {
    int i_ind = a[i];
    int j_ind = a[j];
    a[i] = j_ind;
    a[j] = i_ind;
}

int main(void) {

    int t[] = {1, 2, 3, 4, 5};

    if (is_sorted(t, 5)) {
        printf("Hello");
    } else {
        printf("boo!");
    }

    return 0;
}