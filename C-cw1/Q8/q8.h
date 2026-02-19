// Purpose: Declares the Polynomial struct and function prototypes for polynomial operations,
// including creation, addition, subtraction, multiplication, evaluation, and printing.

#ifndef Q8_H
#define Q8_H

// Definition of the Polynomial linked list node structure.
typedef struct polynominal
{
    double coef;
    int pow;
    struct polynominal *nex;
} Polynomial;

// Function prototypes for polynomial operations.
Polynomial *readPoly(void);
Polynomial *createTerm(double coef, int pow);
Polynomial *addTerm(Polynomial* p, double coef, int pow);
Polynomial *add(Polynomial *poly1, Polynomial *poly2);
Polynomial *subtract(Polynomial *poly1, Polynomial *poly2);
Polynomial *multiply(Polynomial *poly1, Polynomial *poly2);
double getValue(Polynomial *p, double x);
void printPoly(Polynomial *p);

void freePoly(Polynomial *head);

#endif // Q8_H