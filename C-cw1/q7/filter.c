// Purpose: Implements helper functions for filtering numbers, such as marking multiples,
// finding the next divisor, and printing the filtered list. Intended for use in (a).

#include <stdio.h>
#include "q7.h"

//  Marks multiples of the current divisor as 0 in the nums array.
void markNumbers(int *nums, int N, int div)
{
    for (int i = div + 1; i < N - 1; i++)
    {
        if (nums[i] > 0 && nums[i] % nums[div] == 0)
            nums[i] = 0;
    }
}

// Finds the index of the next divisor in the nums array after the current divisor.
int getNextDiv(int *nums, int N, int div)
{
    for (int i = div + 1; i < N - 1; i++)
    {
        if (nums[i] > 0)
            return i;
    }
    return 0;
}

//  Prints the numbers in the nums array that are not marked as 0.
void printNumbers(int *nums, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (nums[i] > 0)
        {
            printf("%d", nums[i]);
            printf(" ");
        }
    }
    printf("\n");
}