// Purpose: Finds and prints all two-digit digit-cancelling fractions.

#include <stdio.h>
#include <stdlib.h>
#include "q5.h"

int main(void)
{
    // Loop through all two-digit numerators and denominators
    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            // Check if a/b is a digit-cancelling fraction
            if (checkFraction(i, j))
            {
                printf("%d/%d\n", i, j);
            }
        }
    }
    return EXIT_SUCCESS;
}