#include "q5.h"

int checkFraction(int a, int b)
{
    int a0 = a % 10;
    int a1 = (a - a0) / 10;
    int b0 = b % 10;
    int b1 = (b - b0) / 10;
    if (a0 == b0 && a1 == b1)
        return 0;
    else if (!a1 || !b1)
        return 0;
    else if (a0 == b1 && a1 * b == a * b0)
        return 1;
    else if (a1 == b0 && a0 * b == a * b1)
        return 1;
    return 0;
}