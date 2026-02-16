/*
Write a program which reads in two characters and outputs them in reverse order.
*/
#include <math.h>
#include <stdio.h>

int main()
{
    char a, b;
    printf("Please type in the first char. ");
    scanf(" %c", &a);
    printf("Please type in the second char. ");
    scanf(" %c", &b);

    printf("The reversed chars are: ");
    printf("%c %c", b, a);
}