#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

//---------- I. Piles d’entiers ----------

struct stack {
  int *a;
  int size;
  int capacity;
};
typedef struct stack stack;

//-- 1 --
stack *stack_new(void){
    stack *pile = malloc(sizeof(stack));
    pile->a = NULL;
    pile->size = 0;
    pile->capacity = 0;
    return pile;
}

void stack_delete(stack *s){
    if (s!=NULL){
        free(s->a);
        free(s);
    }

}

//-- 2 --
bool stack_is_empty(stack *s){
    return(s->size==0);
}

//-- 3 --
int stack_top(stack *s){
    assert(s->a!=NULL);
    return s->a[s->size-1];
}

int stack_pop(stack *s){
    assert(s->size>0);
    int res = s->a[s->size-1];
    s->size = s->size -1;
    return res;
}

//-- 4 --
void stack_resize(stack *s, int r){
    assert(r>(s->capacity));
    int *b = malloc(r*sizeof(int));
    for (int i =0; i<(s->size); i++){
        b[i] = s->a[i];
    }
    free(s->a);
    s->a = b;
    s->capacity = r;
}

//-- 5 --
void stack_push(stack *s, int i){
    if (s->capacity == 0){
        stack_resize(s,1);
    }
    if (s->size == s->capacity){
        stack_resize(s,s->size*2);
    }
    s->a[s->size] = i;
    s->size = s->size + 1;
}

//---------- II. Présentation générale des algorithmes, orientation ----------

struct point {
int x;
int y;
};
typedef struct point point;

int plus_bas(point t[], int n) {
    int j = t[0].y;
    int abs = 0;

    for (int i=1; i < n; i++) { //Valeur 0 mis en donnée
        if (t[i].y <= j) {
            if (t[i].y == j) {
                if (t[abs].x > t[i].x) {
                    abs = i;
                    j = t[i].y;
                }
            } else {
                j = t[i].y;
                abs = i;
            }
        }
    }
    return abs;
}

// Fonction pour les abscisses

int orientation(point t[], int i, int j, int k) {
    point i_point = t[i];
    point j_point = t[j];
    point k_point = t[k];
    int phi = (k_point.y - i_point.y) * (j_point.x - i_point.x) - (k_point.x - i_point.x) * (j_point.y - i_point.y);
    if (phi ==0) {
        return 0;
    } else if (phi > 0) {
        return 1;
    } else{ 
        return -1;
    }
}

//---------- III. Algorithme du paquet cadeau ----------

// -- 2 --
int prochain_point(point t[], int n, int i){
    assert(n!=0);
    int max = 0;
    for (int j=1;j<n;j++){
        if (j!=i && orientation(t,i,j,max)<=0){
            max = j;
        }
    }
    return max;
}

// -- 4 --
stack *convexe_jarvis(point t[], int n){
    int bas = plus_bas(t,n);
    stack *enveloppe = stack_new();
    stack_push(enveloppe,bas);
    int consider = prochain_point(t,n,bas);
    while(consider!=bas){
        stack_push(enveloppe,consider);
        consider = prochain_point(t,n,consider);
    }
    return enveloppe;
}

// --------- IV. Algorithme de balayage -----------------

void tri_insertion(point t[], int n) {
    for (int i = 1; i < n; i++) {
        point cle = t[i];
        int j = i - 1;

        while (j >= 0 && (t[j].x > cle.x || (t[j].x == cle.x && t[j].y > cle.y))) {
            t[j + 1] = t[j];
            j--;
        }
        t[j + 1] = cle;
    }
}


void maj_es(stack *es, point t[], int i) {
    while (es->size >= 2) {
        int j = es->a[es->size - 1];
        int k = es->a[es->size - 2];
        if (orientation(t, k, j, i) >= 0) break; 
        (void)stack_pop(es);                   
    }
    stack_push(es, i);
}

void maj_ei(stack *ei, point t[], int i) {
    while (ei->size >= 2) {
        int j = ei->a[ei->size - 1];
        int k = ei->a[ei->size - 2];
        if (orientation(t, k, j, i) <= 0) break; 
        (void)stack_pop(ei);
    }
    stack_push(ei, i);
}


stack *convexe_grapham(point t[], int n) {
    assert(n >= 1);

    tri_insertion(t, n);

    stack *ei = stack_new();
    stack *es = stack_new();
    stack *res = stack_new();

    for (int i = 0; i < n; i++) maj_ei(ei, t, i);
    for (int i = n - 1; i >= 0; i--) maj_es(es, t, i);

    for (int i = 0; i < ei->size; i++) stack_push(res, ei->a[i]);
    for (int i = 2; i + 1 < es->size; i++) stack_push(res, es->a[i]);

    stack_delete(ei);
    stack_delete(es);
    return res;
}

int main(void) {

    point t[] = {{0, 0}, {1, 4}, {1, 8}, {4, 1}, {4, 4}, {5, 9}, {5, 6}, {7, -1}, {7, 2}, {8, 5}, {11, 6}, {13, 1}};

    stack *pile = convexe_grapham(t, 12);

    for (int i = 0; i < pile->size; i++) {
        int index = pile->a[i];
        printf("Point: (%d, %d)\n", t[index].x, t[index].y);
    }

    printf("Taille de la pile: %d\n", pile->size);

    stack_delete(pile);
    return 0;
}