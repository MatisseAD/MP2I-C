#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// Exercice A3

bool est_puissance_deux(uint64_t n) {    
    return  (n & (n-1)) == 0;
}

int popcount(uint64_t n) {
    if (est_puissance_deux(n)) {
        return 1;
    } else {
        int cpt = 0;
        while (n != 0) {
            n >> 1;
            cpt += 1;
        }
        return cpt;
    }
}

// Exercice C5

void swap(int a[], int i, int j) {
    int pivot = a[i];
    a[i] = a[j];
    a[j] = pivot;
}

void dutch_flag_2n_swap(int a[], int n) {
    int i = 0;

    for (int k = 0; k < n; k++) {
        if (a[k] == 0) {
            swap(a, i, k);
            i += 1;
        }
    }

    for (int k = i; k < n; k++) {
        if (a[k] == 1) {
            swap(a, i, k);
            i += 1;
        }
    }
}


void dutch_flag_n_swap(int a[], int n) {
        int i = 0;
        int j = 0;

        for (int k=0; k < n; k++) {
            if (a[k] == 0) {
                if (a[i] != 1) {
                    swap(a,i,k);
                    i += 1;
                    j += 1;
                } else {
                    swap(a, i, j);
                    swap(a, i, k);
                    i += 1;
                    j += 1;
                }
        } else if (a[k] == 1) {
                swap(a, j, k);
                j += 1;
        }
    }
}

// Exercice C10

int nombre_occurences(int t[], int n, int k) {
    int cpt = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == k) {
            cpt += 1;
        }
    }
    return cpt;
}

    int* tableau_occurences(int t[], int n, int m) {
        int *t_occ = malloc((m+1) * sizeof(int));
        for (int i = 0; i < m; i++) {
            t_occ[i] = nombre_occurences(t,n,i);
        }
        return t_occ;
    }

void tri_denombrement(int t[], int n, int m) {

    int* t_b = tableau_occurences(t,n,m);

    int i = 0;
    int rang = 0;

    while (i < n) {
        for (int k =0; k <= t_b[i]; k++) {
            t[rang] = i;
            rang++;
        }
        i++;
    }

    free(t_b);

}

int main(void) {

    if (est_puissance_deux(8)) {
        printf("Yes, it's a power of 2! \n");
    } else {
        printf("Nope");
    }

    if (!est_puissance_deux(6)) {
        printf("Boo, it's not a power of two! \n");
    } 

    if (est_puissance_deux(256)) {
        printf("yeahhhh! \n");
    }

    int a[] = {1, 2, 2, 1, 0, 0, 1, 0};
    int b[] = {1, 2, 2, 1, 0, 0, 1, 0};

    dutch_flag_2n_swap(a, 8);
    dutch_flag_n_swap(b, 8);

    // print arrays
    printf("Array after dutch_flag_2n_swap: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Array after dutch_flag_n_swap: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    int alpha[] = {20, 19, 18, 17, 17, 17, 15, 14, 12, 13, 10, 12, 15, 18, 19, 20};
    tri_denombrement(alpha, 16, 20);
    printf("Array after tri_denombrement: ");
    for (int i = 0; i < 16; i++) {
        printf("%d ", alpha[i]);
    }
    printf("\n");
    
    return 0;
}

