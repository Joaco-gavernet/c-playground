#ifndef ISTACK_H_INCLUDED
#define ISTACK_H_INCLUDED

struct tnodo {
  int dato;
  struct tnodo * sig;
};
typedef struct tnodo nodo;

struct tstack {
  int dim;
  nodo * first;
};
typedef struct tstack stack;


stack * s_create();
int s_push(stack * s, int n);
int s_pop(stack * s);
int s_top(stack s);
int s_empty(stack s);
int s_length(stack s);

#endif