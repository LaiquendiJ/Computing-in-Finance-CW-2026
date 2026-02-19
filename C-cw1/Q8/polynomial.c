// Purpose: Implements polynomial operations using a linked list.
// Functions: creation, addition, subtraction, multiplication, evaluation, and printing.

#include <stdio.h>
#include <stdlib.h>
#include "q8.h"

// Create a new term with given coefficient and power, and return the pointer to the term.
Polynomial *createTerm(double coef, int pow)
{
    Polynomial *term = (Polynomial *)malloc(sizeof(Polynomial));
    term->coef = coef;
    term->pow = pow;
    term->nex = NULL;
    return term;
}

// Insert term in descending exponent order, and combine like terms if necessary. 
// Return the head of the polynomial linked list.
Polynomial *addTerm(Polynomial *p, double coef, int pow)
{
    if (coef == 0)
        return p;
    if (p == NULL)
    {
        return createTerm(coef, pow);
    }
    Polynomial *head = p;
    Polynomial *pre = NULL;

    if (pow > p->pow)
    {
        Polynomial *res = createTerm(coef, pow);
        res->nex = p;
        return res;
    }
    while (p)
    {
        if (pow == p->pow)
        {
            p->coef += coef;
            if (p->coef == 0)
            {
                if (pre)
                    pre->nex = p->nex;
                else
                    head = p->nex;
                free(p);
            }
            return head;
        }
        else if (pow > p->pow)
        {
            Polynomial *res = createTerm(coef, pow);
            res->nex = p;
            pre->nex = res;
            return head;
        }
        pre = p;
        p = p->nex;
    }
    pre->nex = createTerm(coef, pow);
    return head;
}

// Read polynomials terms from user input and return the polynomial linked list.
Polynomial *readPoly(void)
{
    Polynomial *head = NULL;
    Polynomial *pointer = NULL;
    int n, pow;
    double coef;

    printf("Number of input terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Coefficient and power: ");
        scanf("%lf %d", &coef, &pow);
        head = addTerm(head, coef, pow);
    }
    return head;
}

// Add two polynomials linked list and return the result as a new linked list.
Polynomial *add(Polynomial *poly1, Polynomial *poly2)
{
    Polynomial *new_poly = NULL;
    Polynomial *p = NULL;

    float coef;
    int pow;
    while (poly1 || poly2)
    {
        if (poly1 && (!poly2 || poly1->pow > poly2->pow))
        {
            coef = poly1->coef;
            pow = poly1->pow;
            poly1 = poly1->nex;
        }
        else if (poly2 && (!poly1 || poly1->pow < poly2->pow))
        {
            coef = poly2->coef;
            pow = poly2->pow;
            poly2 = poly2->nex;
        }
        else
        {
            coef = poly1->coef + poly2->coef;
            pow = poly1->pow;
            poly1 = poly1->nex;
            poly2 = poly2->nex;
        }
        if (!new_poly && coef)
        {
            new_poly = createTerm(coef, pow);
            p = new_poly;
        }
        else if (coef)
        {
            p->nex = createTerm(coef, pow);
            p = p->nex;
        }
    }
    return new_poly;
}

// Subtract two polynomials linked list and return the result as a new linked list.
Polynomial *subtract(Polynomial *poly1, Polynomial *poly2)
{
    Polynomial *new_poly = NULL;
    Polynomial *p = NULL;

    double coef;
    int pow;
    while (poly1 || poly2)
    {
        if (poly1 && (!poly2 || poly1->pow > poly2->pow))
        {
            coef = poly1->coef;
            pow = poly1->pow;
            poly1 = poly1->nex;
        }
        else if (poly2 && (!poly1 || poly1->pow < poly2->pow))
        {
            coef = -poly2->coef;
            pow = poly2->pow;
            poly2 = poly2->nex;
        }
        else
        {
            coef = poly1->coef - poly2->coef;
            pow = poly1->pow;
            poly1 = poly1->nex;
            poly2 = poly2->nex;
        }
        if (!new_poly && coef)
        {
            new_poly = createTerm(coef, pow);
            p = new_poly;
        }
        else if (coef)
        {
            p->nex = createTerm(coef, pow);
            p = p->nex;
        }
    }
    return new_poly;
}
// Multiply two polynomials linked list and return the result as a new linked list.
Polynomial *multiply(Polynomial *poly1, Polynomial *poly2)
{
    if (!poly2)
        return NULL;
    Polynomial *p1 = poly1;
    Polynomial *new_poly = createTerm(poly2->coef * poly1->coef, poly1->pow + poly2->pow);
    Polynomial *p = new_poly;
    p1 = p1->nex;
    double coef;
    int pow;
    while (p1)
    {
        p->nex = createTerm(poly2->coef * p1->coef, p1->pow + poly2->pow);
        p = p->nex;
        p1 = p1->nex;
    }
    poly2 = poly2->nex;
    return add(multiply(poly1, poly2), new_poly);
}

// Evaluate the polynomial linked list at a given value of x and return the result as a double.
double getValue(Polynomial *p, double x)
{
    if (!p)
        return 0.0;
    Polynomial *pointer = p->nex;
    double res = p->coef;
    for (int i = p->pow; i >= 1; i--)
    {
        if (pointer && pointer->pow == i - 1)
        {
            res = res * x + pointer->coef;
            pointer = pointer->nex;
        }
        else
        {
            res = res * x;
        }
    }
    return res;
}

// Print the polynomial linked list.
void printPoly(Polynomial *p)
{
    printf("%fx^%d", p->coef, p->pow);
    p = p->nex;
    while (p)
    {
        if (p->pow == 0)
        {
            if (p->coef < 0)
                printf("%f", p->coef);
            else
                printf(" + %f", p->coef);
            break;
        }
        if (p->coef < 0)
            printf("%fx^%d", p->coef, p->pow);
        else
            printf(" + %fx^%d", p->coef, p->pow);

        p = p->nex;
    }
    printf("\n");
}