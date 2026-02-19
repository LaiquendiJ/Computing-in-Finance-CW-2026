// Purpose: Declares functions for filtering and printing numbers.

#ifndef Q7_H
#define Q7_H

// (a) Including all numbers.
void markNumbers(int *nums, int N, int div);
int getNextDiv(int *nums, int N, int div);

// (b) Excluding all even numbers. 
void markNumbers2(int *nums, int N, int div);
int getNextDiv2(int *nums, int N, int div);

void printNumbers(int *nums, int N);

#endif // Q7_H