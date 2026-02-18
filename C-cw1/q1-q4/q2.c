/*
Purpose: Determines how many times each of the given for loops executes.
(a) for (i=10; i<=10; i++);
(b) for (i=10; i<10; i++);
(c) for (i=10; i>=1; i-=4);
(d) for (i=10; i==1; i-=4);
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;

    // (a) Loop runs once, when i=10.
    for (int i = 10; i <= 10; i++)
        num1++;

    // (b) Loop does not run at all, since i is not less than 10.
    for (int i = 10; i < 10; i++)
        num2++;

    // (c) Loop runs three times, when i=10, i=6, and i=2.
    for (int i=10; i>=1; i-=4)
        num3++;

    // (d) Loop does not run at all, since i is not equal to 1.
    for (int i=10; i==1; i-=4)
        num4++;

    printf("Loop (a) will be executed %d time.\n", num1);
    printf("Loop (b) will be executed %d times.\n", num2);
    printf("Loop (c) will be executed %d times.\n", num3);
    printf("Loop (d) will be executed %d times.\n", num4);

    return EXIT_SUCCESS;
}