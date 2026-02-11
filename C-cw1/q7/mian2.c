#include "q7.h"

int main(void)
{
    int n;
    scanf("%d", &n);

    int size;
    if (n % 2 == 0)
        size = n / 2 - 1;
    else
        size = n / 2;

    int marks[size];
    int nums[size];
    for (int i = 0; i < size; i++)
    {
        marks[i] = 1;
        nums[i] = i * 2 + 3;
    }
    int div = 0;
    while (nums[div] <= sqrt(n))
    {
        markNumbers2(nums, marks, size, div);
        div = getNextDiv2(nums, marks, size, div);
    }
    if (n >= 2)
    {
        printf("%d", 2);
        printf(" ");
    }
    else
        return;
    printNumbers2(nums, marks, size);
}