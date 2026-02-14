    #include <stdbool.h>
    #include <stdlib.h>
    #include <assert.h>
    #include <stdio.h>

    // En tête

    struct point {
        int x;
        int y;
    };

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


    typedef struct point point;

    // Fin en de tête

    // Fonction pour les ordonnées

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
        phi = (k_point.y - i_point.y) * (j_point.x - i_point.x) - (k_point.x - i_point.x) * (j_point.y - i_point.y);
        if (i_point == j_point) || (i_point == k_point) || (j_point == k_point) {
            return 0;
        } else {
            if (phi > 0) {
                return 1;
            } else {
                return -1;
            }
        }
    }

    // Tri insertion pour les abscisses

void tri_insertion(point t[], int n) {
    for (int i = 1; i < n; i++) {
        point cle = t[i];
        int j = i - 1;

        while (j >= 0 && t[j].x > cle.x) {
            t[j + 1] = t[j];
            j--;
        }

        t[j + 1] = cle;
    }
}


    void maj_es(stack *es, point t[], int i) {
        
    }

    void maj_ei(stack *ei, point t[], int i) {

    }

    stack *convexe_grapham(point t[], int n) {

    }

    int main(void) {
        point t[] = {{0, 0}, {1, 4}, {1, 8}, {4, 1}, {4, 4}, {5, 9}, {5, 6}, {7, -1}, {7, 2}, {8, 5}, {11, 6}, {13, 1}};

        tri_insertion(t,12);
        
        return 0;
    }