// Purpose: Reads an integer n, finds all primes ≤ n, and prints them.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "q7.h"

int main(void)
{
    // Read an integer n from the user and validate it.
    int n;
    printf("Enter an integer equal or larger than 2: ");
    scanf("%d", &n);
    if (n < 2){
        printf("Please give a integer equal or larger than 2!");
        return EXIT_SUCCESS;
    }

    // (a) Including all numbers from 2 to n in the nums array.
    int nums[n - 2];
    for (int i = 2; i < n + 1; i++)
    {
        nums[i - 2] = i;
    }

    // Use the Sieve of Eratosthenes algorithm to mark non-prime numbers in the nums array.
    int div = 0;
    while (div < n - 2 &&nums[div] <= sqrt(n))
    {
        markNumbers(nums, n, div);
        div = getNextDiv(nums, n, div);
    }

    // Print the unmarked numbers in the nums array.
    printf("(a) The prime numbers smaller than or equal to %d are:  ", n);
    printNumbers(nums, n-1);

    // (b) Excluding all even numbers from the nums_opt array, starting from 3.
    // Determine the size of the nums_opt array based on whether n is even or odd.
    int size;
    if (n % 2 == 0)
        size = n / 2 - 1;
    else
        size = n / 2;

    // Fill the nums_opt array with odd numbers starting from 3 up to n.
    int nums_opt[size];
    for (int i = 0; i < size; i++)
    {
        nums_opt[i] = i * 2 + 3;
    }

    // Use the optimized Sieve of Eratosthenes algorithm to mark non-prime numbers in the nums_opt array.
    int div_opt = 0;
    while (div_opt < size &&nums_opt[div_opt] <= sqrt(n))
    {
        markNumbers2(nums_opt, size, div_opt);
        div_opt = getNextDiv2(nums_opt, size, div_opt);
    }
    
    // Print the unmarked numbers in the nums_opt array, along with the prime number 2.
    printf("(b) Using the optimized algorithm, the prime numbers smaller than or equal to %d are:  ", n);
    printf("%d", 2);
    printf(" ");
    printNumbers(nums_opt, size);

    return EXIT_SUCCESS;
}