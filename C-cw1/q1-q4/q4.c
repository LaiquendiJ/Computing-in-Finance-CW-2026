/*
Write a program which reads in 200 characters and outputs them in reverse order. Do not use arrays. Hint: use recursion.
*/

#include <math.h>
#include <stdio.h>
int n = 200;

void reversed(char s[], int i)
{
    if (i == n)
        return;
    reversed(s, i + 1);
    printf("%c", s[i]);
}

int main()
{
    char s[n + 1];
    scanf("%s", s);
    reversed(s, 0);
}