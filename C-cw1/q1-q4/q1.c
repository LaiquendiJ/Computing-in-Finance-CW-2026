// Reads in two characters and outputs them in reverse order.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a, b;

    // Read in two characters.
    printf("Please type in the first char. ");
    scanf(" %c", &a);
    printf("Please type in the second char. ");
    scanf(" %c", &b);

    // Output the characters in reverse order.
    printf("The reversed chars are: ");
    printf("%c %c\n", b, a);

    return EXIT_SUCCESS;
}