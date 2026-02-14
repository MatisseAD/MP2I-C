#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

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

int main(void){
    return 0;
}