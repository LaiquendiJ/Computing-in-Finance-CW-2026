#include <math.h>
#include <stdio.h>
int n = 10;
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