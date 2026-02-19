#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

/* Cross out multiples of nums[div] among later indices */
static void markNumbers(const int *nums, int *marks, int len, int div) {
    int p = nums[div];
    for (int i = div + 1; i < len; i++) {
        if (marks[i] && nums[i] % p == 0) {
            marks[i] = 0;
        }
    }
}

/* Find next marked index after div; return -1 if none */
static int getNextDiv(const int *marks, int len, int div) {
    for (int i = div + 1; i < len; i++) {
        if (marks[i]) return i;
    }
    return -1;
}

/* Print all marked numbers */
static void printNumbers(const int *nums, const int *marks, int len) {
    for (int i = 0; i < len; i++) {
        if (marks[i]) {
            printf("%d ", nums[i]);
        }
    }
}

/* 
    Note that the two versions of sieve are very similar, and we can easily modify one to get the other.
    They also share the same helper functions, so we can reuse those without modification.
*/

/* ---------- Version A: standard sieve ---------- */
/* 
    Stores nums = 2..n inclusive => len = n-1 elements.
    Index i represents number i+2, so div starts at 0 for number 2.
    We can stop when div^2 > n, since all composites <= n must have a factor <= sqrt(n).
*/
void sieve_standard_print(int n) {
    if (n < 2){
        printf("No primes\n");
        return;
    }

    int len = n - 1;
    int nums[len];
    int marks[len];

    for (int i = 0; i < len; i++) {
        nums[i] = i + 2;  // numbers from 2 to n
        marks[i] = 1;     // all initially marked as prime
    }

    int div = 0;  // start with first number 2
    while (div != -1 && nums[div] * nums[div] <= n) {
        markNumbers(nums, marks, len, div);
        div = getNextDiv(marks, len, div);
    }

    printNumbers(nums, marks, len);
}

/* ---------- Version B: odd-only (half memory) ---------- */
/*
    Store only odd candidates 3,5,7,...,n, plus we always print 2 separately.
    Index i represents odd number (2*i + 3).
    We can stop when div^2 > n, since all composites <= n must have a factor <= sqrt(n).
*/
void sieve_oddonly_print(int n) {
    if (n < 2){
        printf("No primes\n");
        return;
    }

    printf("2 "); // print 2 separately

    if (n < 3) {
        printf("\n");
        return;
    }

    int len;
    if (n % 2 == 0) {
        len = n / 2 - 1; // n is even
    }
    else {
        len = n / 2;     // n is odd
    }
    int nums[len];
    int marks[len];

    for (int i = 0; i < len; i++) {
        nums[i] = 2 * i + 3;  // numbers 3, 5, 7, ..., n
        marks[i] = 1;     // all initially marked as prime
    }

    int div = 0;  // start with first number 3
    while (div != -1 && nums[div] * nums[div] <= n) {
        markNumbers(nums, marks, len, div);
        div = getNextDiv(marks, len, div);
    }

    printNumbers(nums, marks, len);
}