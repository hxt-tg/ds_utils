/* complex.c */
#include "complex.h"
#include <stdio.h>
#include <stdlib.h>

Complex createComplex(double real, double imag) {
    Complex complex = (Complex) malloc(sizeof(struct Complex));
    complex->real = real;
    complex->imag = imag;
    return complex;
}

void freeComplex(Complex com) {
    free(com);
}

Complex addComplex(Complex dest, Complex com) {
    dest->real += com->real;
    dest->imag += com->imag;
    return dest;
}

Complex subComplex(Complex dest, Complex com) {
    dest->real -= com->real;
    dest->imag -= com->imag;
}

Complex mulComplex(Complex dest, Complex com) {
    double temp_real = dest->real * com->real - dest->imag * com->imag;
    dest->imag = dest->real * com->imag + dest->imag * com->real;
    dest->real = temp_real;
    return dest;  
}

Complex divComplex(Complex dest, Complex com) {
    double denominator, temp_real;
    denominator = com->real * com->real + com->imag * com->imag;
    temp_real = (dest->real * com->real + dest->imag * com->imag) / denominator;
    dest->imag = (dest->imag * com->real - dest->real * com->imag) / denominator;
    dest->real = temp_real;
    return dest; 
}

void printComplex(Complex com) {
    if (com->real == 0 && com->imag == 0) {
        printf("0");
    } else if (com->real == 0 && com->imag == 1) {
        printf("i");
    } else if (com->real == 0 && com->imag == -1) {
        printf("-i");
    } else if (com->real == 0){
        printf("%lfi");
    } else if (com->imag == 0) {
        printf("%lf", com->real);
    } else if (com->imag < 0) {
        printf("%lf%lfi", com->real, com->imag);    
    } else {
        printf("%lf+%lfi", com->real, com->imag);
    } 
    printf("\n");
}



