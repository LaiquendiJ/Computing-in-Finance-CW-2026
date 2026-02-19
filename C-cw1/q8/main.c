// Purpuse: To perform addition, subtraction, multiplication and evaluation of two polynomials

#include <stdio.h>
#include <stdlib.h>
#include "q8.h"

int main(void)
{
    // Read two polynomials from user input and print it. 
    printf("First polynomial\n");
    Polynomial *a = readPoly();
    printf("Second polynomial\n");
    Polynomial *b = readPoly();
    printf("The first polynomial is:\n");
    printPoly(a);
    printf("The second polynomial is:\n");
    printPoly(b);

    // Perform addition, subtraction, multiplication of the two polynomials and print the results.
    printf("The sum of two polynomials is:\n");
    printPoly(add(a, b));
    printf("The difference of two polynomials is:\n");
    printPoly(subtract(a, b));
    printf("The product of two polynomials is:\n");
    printPoly(multiply(a, b));
    
    // Evaluate the first polynomial at a given value of x and print the result.
    float x;
    printf("The input value of x: ");
    scanf("%f", &x);
    printf("The value of the first polynomial with x=%f is %f\n", x, getValue(a, x));

    return EXIT_SUCCESS;
}