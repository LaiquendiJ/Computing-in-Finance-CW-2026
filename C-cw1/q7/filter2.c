#include "q7.h"

void markNumbers2(int *nums, int N, int div)
{
    for (int i = div + 1; i < N; i++)
    {
        if (nums[i]>0 && nums[i] % nums[div] == 0)
            nums[i] = 0;
    }
}
int getNextDiv2(int *nums, int N, int div)
{
    for (int i = div + 1; i < N; i++)
    {
        if (nums[i]>0)
            return i;
    }
    return 0;
}