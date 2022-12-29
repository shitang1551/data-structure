#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n;
    char s[100];
    scanf("%d", &n);
    s[0] = n;
    for (int i = 1; i <= n; i++)
        scanf(" %c", &s[i]);
    int next[100];
    next[0] = 0;
    int i = 1, j = 0;
    // printf("%d", l);
    next[1] = 0;
    while (i < n)
    {
        if (j == 0 || s[i] == s[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
    for (i = 1; i <= n; i++)
    {
        printf("%d ", next[i] - 1);
    }
    return 0;
}