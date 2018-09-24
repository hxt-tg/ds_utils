#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "stack.h"
#define ESTACKNOTALLOC 233
#define ESTACKEMPTY    666


void processError(int errorCode, const char *info){
    fprintf(stderr, "Error [%d]: %s.\n", errorCode, info);
    exit(errorCode);
}


Stack createStack(size_t elementSize){
    Stack s = (Stack) malloc (sizeof(struct Stack));
    if (!s) processError(ENOMEM, "No memory");
    s->base = s->top = NULL;
    s->esize= elementSize;
    s->ssize = 0;
    s->label = NULL;
    return s;
}


void deleteStack(Stack s){
    if (s){
        if (s->base) free(s->base);
        if (s->label) free(s->label);
        free(s);
    }
}


void initStack(Stack s){
    if (!s) processError(ESTACKNOTALLOC, "Stack does not existed");
    s->base = malloc(s->esize * INIT_SIZE);
    if (!s->base) processError(ENOMEM, "No memory");
    s->ssize = s->esize * INIT_SIZE;
}


void setStackLabel(Stack s, const char *label){
    if (!s) processError(ESTACKNOTALLOC, "Stack does not existed");
    if (s->label) free(s->label);
    size_t labelMem = strlen(label) + 1;
    s->label = (char*) malloc(sizeof(char) * labelMem);
    if (!s->label) processError(ENOMEM, "No memory");
    memcpy(s->label, label, labelMem);
    
}


char *getStackLabel(Stack s, char *dest){
    if (!s) processError(ESTACKNOTALLOC, "Stack does not existed");
    if (!s->label) return NULL;
    strcpy(dest, s->label);
    return dest;
}


void pushStack(Stack s, const void *elem){
    if (!s) processError(ESTACKNOTALLOC, "Stack does not existed");
    if (s->top - s->base >= s->ssize/s->esize){
        int mem_shift = s->top - s->base;
        void *temp = realloc(s->base, s->ssize + s->esize * INCREMENT);
        if (!temp) processError(ENOMEM, "No memory");
        s->base = temp;
        s->top = s->base + mem_shift;
        s->ssize += s->esize * INCREMENT;
    }
    memcpy(s->top, elem, s->esize);
    s->top += s->esize;
}


void popStack(Stack s, void *dest){
    if (!s) processError(ESTACKNOTALLOC, "Stack does not existed");
    if (isEmptyStack(s))
        processError(ESTACKEMPTY, "Stack is empty");
    memcpy(dest, s->top - s->esize, s->esize);
    s->top -= s->esize;
}


void peekStack(Stack s, void *dest){
    if (!s) processError(ESTACKNOTALLOC, "Stack does not existed");
    if (isEmptyStack(s))
        processError(ESTACKEMPTY, "Stack is empty");
    memcpy(dest, s->top - s->esize, s->esize);
}


int isEmptyStack(Stack s){
    if (!s || !s->base) return -1;
    return s->top == s->base;
}


int stackSize(Stack s){
    if (!s || !s->base) return -1;
    return (s->top - s->base)/s->esize;
}



