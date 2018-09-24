/* complex.h */
#ifndef SPHCOMPLEX_H
#define SPHCOMPLEX_H


/* Complex Structure */
typedef struct ComplexS {
    double real;
    double imag;
} *Complex;

Complex createComplex(double real, double imag);
void    freeComplex(Complex com);
Complex addComplex(Complex dest, Complex com);
Complex subComplex(Complex dest, Complex com);
Complex mulComplex(Complex dest, Complex com);
Complex divComplex(Complex dest, Complex com);
int     printComplex(Complex com);

#endif /* SPHCOMPLEX_H */
