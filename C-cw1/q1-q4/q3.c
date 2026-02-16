/*
Write a program that reads numbers until a negative number is read and prints out the number of values read, the largest value, the smallest value, and the range.
*/
#include <stdio.h>

int main()
{
    int cont = 0;
    double max_val, min_val;
    /*
        This loop continues to read integers until a negative number is entered.
        It keeps track of the count of numbers read, as well as the largest and smallest values.
    */
    while (1)
    {
        double val;
        scanf("%lf", &val);
        cont++;
        max_val = (val > max_val) ? val : max_val;
        if (val < 0)
        {
            min_val = val;
            break;
        }
    }
    printf("count=%d, max=%f, min=%f, range=[%f,%f]", cont, max_val, min_val, min_val, max_val);
}