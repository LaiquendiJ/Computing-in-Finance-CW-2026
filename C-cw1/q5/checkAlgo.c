// Purpose: Implements logic to check for fractions as per q5.

#include "q5.h"

// Returns 1 if the fraction suffice. 
int checkFraction(int a, int b)
{
    // Extract the digits of a and b.
    int a0 = a % 10;
    int a1 = (a - a0) / 10;
    int b0 = b % 10;
    int b1 = (b - b0) / 10;

    // If digits are identical, not a valid case.
    if (a0 == b0 && a1 == b1)
        return 0;

    // If both units digits are zero, valid case.
    else if (a0 == b0 && a0 == 0)
        return 1;

    // If either tens digit is zero, not a valid case.
    else if (!a1 || !b1)
        return 0;

    // If cancelling a0 and b1 gives the same fraction.
    else if (a0 == b1 && a1 * b == a * b0)
        return 1;

    // If cancelling a1 and b0 gives the same fraction.
    else if (a1 == b0 && a0 * b == a * b1)
        return 1;

    return 0;
}