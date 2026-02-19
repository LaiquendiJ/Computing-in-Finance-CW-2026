// Purpose: Implements helper functions for filtering numbers, such as marking multiples,
// and finding the next divisor. Intended for use in (b).

#include "q7.h"

//  Marks multiples of the current divisor as 0 in the nums array.
void markNumbers2(int *nums, int N, int div)
{
    for (int i = div + 1; i < N; i++)
    {
        if (nums[i] > 0 && nums[i] % nums[div] == 0)
            nums[i] = 0;
    }
}

// Finds the index of the next divisor in the nums array after the current divisor.
int getNextDiv2(int *nums, int N, int div)
{
    for (int i = div + 1; i < N; i++)
    {
        if (nums[i] > 0)
            return i;
    }
    return 0;
}