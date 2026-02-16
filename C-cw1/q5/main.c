/*
When his teacher asked Sleepy to simplify the fraction 26/65, he simply cancelled the digit 6 both from the numerator and denominator. To the teacher’s amazement, Sleepy’s cancellation technique produced the correct result:
26/65 = 2/5
Write a program to determine all the fractions with two-digit numerators and denominators for which Sleepy’s technique gives the right answer. (Split your program into functions and divide them between files in an ordered way.)
*/
#include "q5.h"

int main(void)
{
    /* 
    Loop through all two-digit numerators and denominators, and check if they form a "sleepy fraction". 
    If they do, cancel the common digit and print the original and simplified fractions. 
    */
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