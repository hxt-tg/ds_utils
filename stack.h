#ifndef STACK_LIB_H
#define STACK_LIB_H

#include <stdlib.h>

#define INCREMENT  5
#define INIT_SIZE  10

typedef struct Stack{
    void *base;
    void *top;
    char *label;
    size_t ssize;    /* Stack size (bytes) */
    size_t esize;    /* Element size (bytes) */
} *Stack;

Stack createStack(size_t elementSize);
void  deleteStack(Stack s);
void  initStack(Stack s);
void  setStackLabel(Stack s, const char *label);

void  pushStack(Stack s, const void *elem);
void  popStack(Stack s, void *dest);
void  peekStack(Stack s, void *dest);
int   isEmptyStack(Stack s);
int   stackSize(Stack s);

#endif

