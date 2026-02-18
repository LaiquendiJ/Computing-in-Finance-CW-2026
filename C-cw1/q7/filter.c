#include "q7.h"

void markNumbers(int *nums, int N, int div)
{
    for (int i = div + 1; i < N - 1; i++)
    {
        if (nums[i]>0 && nums[i] % nums[div] == 0)
            nums[i] = 0;
    }
}
int getNextDiv(int *nums, int N, int div)
{
    for (int i = div + 1; i < N - 1; i++)
    {
        if (nums[i]>0)
            return i;
    }
    return 0;
}
void printNumbers(int *nums, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (nums[i]>0)
        {
            printf("%d", nums[i]);
            printf(" ");
        }
    }
}