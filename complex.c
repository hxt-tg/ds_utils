/* complex.c */
#include "complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Complex createComplex(double real, double imag) {
    Complex complex = (Complex) malloc(sizeof(struct ComplexS));
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
    return dest;
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

int printComplex(Complex com) {
    char _img[80];
    sprintf(_img, "%g", com->imag);
    int len = 0;
    if (fabs(com->real-0)>1E-7)    /* real part > 0 ? */
        len += printf("%g%s",com->real, com->imag > 0.0 ? "+":"");
    if (fabs(com->imag-0)>1E-7)    /* imaginary part > 0 ? */
        len += printf("%si",fabs(com->imag-1)<=1E-7 ? "" : fabs(com->imag+1)<=1E-7
                ? "-" : _img);
    if (!len)                        /* print 0 when real part and imaginary part is 0 */
        len += printf("0");
    len += printf("\n");
    return len;
}



