#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int catalan(int n) {
    int sum = 0;
    int t[5];
    t[0] = 1;

    for (int i = 1; i < 5; i++) {
        t[i] = 0;
    }


    for (int i = 1; i < 5; i++) {
        int j = 0;
        printf("%d \n", j);
        while (j < i) {
            sum = sum + t[j] * t[i - 1 - j];
            j++;
        }
        t[i] = sum;
        sum = 0;
    }

    return t[5 - 1];
}

int main(void) {
    int p = catalan(5);

    printf("%d", p);

    return 0;
}