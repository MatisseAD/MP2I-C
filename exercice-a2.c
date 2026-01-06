#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

bool est_pair(uint64_t n) {

    while (n > 2) {
        n -= 2;
    }
    return n == 2;
}

uint64_t fill(int k) {
    uint64_t res = 0;
    int n = k;

    while (n >= 0) {
        res = res + (1 << n);
        n -= 1;
    }

    return res;
}

bool est_divisible(uint64_t n, int k) {
    uint64_t diviseur = 1 << k;
    if (est_pair(n)) {
        uint64_t var = n;
        while (var > 0) {
            var -= diviseur;
        }
        return var == 0;
    } else {
        return false;
    }
}

uint64_t quotient(uint64_t n, int k) {
    uint64_t q = 0;
    uint64_t var = n;
    int diviseur = 1 << k;

    while (var > diviseur) {
        var = var - diviseur;
        q++;
    }
    if (var == diviseur) {
        q++;
    }

    return q;
}

uint64_t reste(uint64_t n, int k) {
    uint64_t var = n;
    int diviseur = 1 << k;

    while (var > diviseur) {
        var = var - diviseur;
    }
    if (var == diviseur) {
        return 0;
    }

    return var;
}

uint64_t extrait(uint64_t n, int k) {
    uint64_t extract = (n >> k);

    if (est_pair(extract)) {
        return 0;
    }
    return 1;
}

uint64_t extrait_zone(uint64_t n, int k, int l) {
    uint64_t length = l;
    uint64_t extractor = fill(length-1) << k;

    return (extractor & n);
}

int main(void) {

    printf("Hello world \n");
    printf("%llu \n", fill(10));
    printf("%llu \n", extrait(2048, 11));
    printf("%llu \n", extrait_zone(369, 1, 4));

    if (est_divisible(2048, 2)) {
        printf("C'est divisble! \n");
        printf("Le reste est : %llu \n", reste(2048, 2));
        printf("Le quotient est : %llu \n", quotient(2048, 2));
    } else {
        printf("C'est pas divisible \n");
        printf("Le reste est : %llu \n", reste(2047, 2));
        printf("Le quotient est : %llu \n", quotient(2047, 2));
    }

    return 0;
}
