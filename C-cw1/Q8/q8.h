#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polynominal
{
    double coef;
    int pow;
    struct polynominal *nex;
} Polynomial;

Polynomial *readPoly(void);
Polynomial *createTerm(double coef, int pow);
Polynomial* addTerm(Polynomial* p, double coef, int pow);
Polynomial *add(Polynomial *poly1, Polynomial *poly2);
Polynomial *subtract(Polynomial *poly1, Polynomial *poly2);
Polynomial *multiply(Polynomial *poly1, Polynomial *poly2);
double getValue(Polynomial *p, double x);
void printPoly(Polynomial *p);