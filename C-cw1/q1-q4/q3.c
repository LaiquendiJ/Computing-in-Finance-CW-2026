// Purpose: Reads numbers until a negative number is entered. Prints count, largest, smallest, and range.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0;
    double max_val = 0, min_val = 0;
    /*
        This loop continues to read integers until a negative number is entered.
        It keeps track of the count of numbers read, as well as the largest value.
        When a negative number is entered, it sets the minimum value to that negative number and breaks the loop.
    */
    while (1)
    {
        double val;
        scanf("%lf", &val);
        count++;    // Increment count for each number read.
        max_val = (val > max_val) ? val : max_val;  // Update max_val if the current value is greater.
        if (val < 0)
        {
            min_val = val;  // Set min_val to the negative number that was entered.
            break;
        }
    }

    // Print results. 
    printf("count=%d, max=%f, min=%f, range=[%f,%f]\n", count, max_val, min_val, min_val, max_val);

    return EXIT_SUCCESS;
}