#include "q7.h"

int main(void)
{
    int n;
    scanf("%d", &n);
    int marks[n - 2];
    int nums[n - 2];
    for (int i = 2; i < n + 1; i++)
    {
        marks[i - 2] = 1;
        nums[i - 2] = i;
    }

    int div = 0;
    while (div < n && nums[div] <= sqrt(n))
    {
        markNumbers(nums, marks, n, div);
        div = getNextDiv(nums, marks, n, div);
    }
    printNumbers(nums, marks, n-1);
}