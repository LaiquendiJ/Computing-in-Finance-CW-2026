#include "q7.h"

void markNumbers(int *nums, int *marks, int N, int div)
{
    for (int i = div + 1; i < N - 1; i++)
    {
        if (marks[i] && nums[i] % nums[div] == 0)
            marks[i] = 0;
    }
}
int getNextDiv(int *nums, int *marks, int N, int div)
{
    for (int i = div + 1; i < N - 1; i++)
    {
        if (marks[i])
            return i;
    }
    return 0;
}
void printNumbers(int *nums, int *marks, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (marks[i])
        {
            printf("%d", nums[i]);
            printf(" ");
        }
    }
}