#include "q7.h"

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n < 2){
        printf("Please give a number equal or larger than 2!");
        return EXIT_SUCCESS;}
    int nums[n - 2];
    for (int i = 2; i < n + 1; i++)
    {
        nums[i - 2] = i;
    }

    int div = 0;
    while (div < n - 2 &&nums[div] <= sqrt(n))
    {
        markNumbers(nums, n, div);
        div = getNextDiv(nums, n, div);
    }
    printf("(a) The prime numbers smaller than or equal to %d are:  ", n);
    printNumbers(nums, n-1);

    int size;
    if (n % 2 == 0)
        size = n / 2 - 1;
    else
        size = n / 2;

    int nums_opt[size];
    for (int i = 0; i < size; i++)
    {
        nums_opt[i] = i * 2 + 3;
    }
    int div_opt = 0;
    while (div_opt < size &&nums_opt[div_opt] <= sqrt(n))
    {
        markNumbers2(nums_opt, size, div_opt);
        div_opt = getNextDiv2(nums_opt, size, div_opt);
    }
    
    printf("\n(b) Using the optimized algorithm, the prime numbers smaller than or equal to %d are:  ", n);
    printf("%d", 2);
    printf(" ");
    printNumbers(nums_opt, size);
}