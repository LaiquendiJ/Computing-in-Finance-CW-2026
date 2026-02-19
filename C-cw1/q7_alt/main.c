#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

int main(void) {
    int n;
    printf("Enter a natural number: ");

    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Please enter a natural number.\n");
        return EXIT_FAILURE;
    }

    printf("Standard Sieve Primes up to %d:\n", n);
    sieve_standard_print(n);

    printf("\nOdd-Only Sieve Primes up to %d:\n", n);
    sieve_oddonly_print(n);

    return EXIT_SUCCESS;
}