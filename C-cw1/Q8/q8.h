#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polynominal
{
    float coef;
    int pow;
    struct  polynominal *nex;
}Polynomial;

Polynomial* createTerm(float coef, int pow);
Polynomial* add(Polynomial* poly1, Polynomial* poly2);
Polynomial* subtract(Polynomial* poly1, Polynomial* poly2);
Polynomial* multiply(Polynomial* poly1, Polynomial* poly2);
float getValue(Polynomial*p, float x);