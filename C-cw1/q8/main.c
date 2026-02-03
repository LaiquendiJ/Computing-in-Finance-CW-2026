#include "q8.h"

int main(void){
    
    printf("First polynomial\n");
    Polynomial* a = readPoly();
    printf("Second polynomial\n");
    Polynomial* b = readPoly();

    printf("The sum of two polynomials is:\n");
    printPoly(add(a, b));
    printf("The difference of two polynomials is:\n");
    printPoly(subtract(a, b));
    printf("The product of two polynomials is:\n");
    printPoly(multiply(a, b));
    float x;
    printf("The input value of x: ");
    scanf("%f", &x);
    printf("The value of the first polynomial with x=%f is %f",x,getValue(a,x));
}