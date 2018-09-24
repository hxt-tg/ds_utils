/* complex.h */
#ifndef SPHCOMPLEX_H
#define SPHCOMPLEX_H


/* Complex Structure */
typedef struct Complex {
    double real;
    double imag;
} *Complex;

Complex createComplex(double real, double imag);
void    freeComplex(Complex com);
Complex addComplex(Complex dest, Complex com);
Complex subComplex(Complex dest, Complex com);
Complex mulComplex(Complex dest, Complex com);
Complex divComplex(Complex dest, Complex com);
void    printComplex(Complex com);

#endif /* SPHCOMPLEX_H */
