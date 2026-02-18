// Purpose: Reads in 200 characters and outputs them in reverse order using recursion. Does not use arrays for storage beyond the input string.

#include <stdio.h>
#include <stdlib.h>

int n = 200;

// Recursively print the string in reverse order. The function takes the string and the current index as parameters.
void reversed(char s[], int i)
{
    // Base case: If the current index reaches n, return from the function.
    if (i == n)
        return;

    // Recursive call to process the next character in the string.
    reversed(s, i + 1);

    // After the recursive call returns, print the current character. 
    // This will print characters in reverse order as the stack unwinds.
    printf("%c", s[i]);
}

int main()
{
    char s[n + 1]; // Buffer for 200 characters plus a null terminator.
    scanf("%s", s);
    reversed(s, 0);
    printf("\n");
    return EXIT_SUCCESS;
}