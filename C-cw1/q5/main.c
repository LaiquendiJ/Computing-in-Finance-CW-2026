#include "q5.h"

int main(void)
{
    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            if (checkFraction(i, j))
            {
                printf("%d / %d\n", i, j);
            }
        }
    }
}