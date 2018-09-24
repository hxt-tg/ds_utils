#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "complex.h"

typedef void (*FPointer)();

void fuck1(){
    printf("fuck1\n");
}

void fuck2(){
    printf("fuck2\n");
}

void stackTestForComplexStruct(){
    printf("========[Stack Test For Complex Struct]========\n");
    int i;
    struct Complex     com1 = {1, 2},
                    com2 = {3, 4};
    Stack s = createStack(sizeof(struct Complex));
    for (i = 0; i < 10; i++){
        pushStack(s, &com1);
        pushStack(s, &com2);
    }
    printf("Size: %d\nPop 6 elements:\n", stackSize(s));
    struct Complex temp;
    for (i = 0; i < 6; i++){
        popStack(s, &temp);
        printComplex(&temp);
    }
    printf("Size: %d\n", stackSize(s));
}

void stackTestForFunctionPointer(){
    printf("========[Stack Test For Function Pointer]========\n");
    int i;
    void *p1 = fuck1, *p2 = fuck2;
    Stack s = createStack(sizeof(void *));
    for (i = 0; i < 10; i++){
        pushStack(s, &p1);
        pushStack(s, &p2);
    }
    printf("Size: %d\nPop 6 elements:\n", stackSize(s));
    void *p;
    for (i = 0; i < 6; i++){
        popStack(s, &p);
        ((void (*)())p)();
    }
    printf("Size: %d\n", stackSize(s));
}

int main(void) {
    stackTestForComplexStruct();
    putchar(10);
    stackTestForFunctionPointer();
    return 0;
}
