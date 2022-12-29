#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[100][100];
int Searchmax(int n, int m)
{
    int i, max = 0;
    int k;
    for (i = 0; i < n; i++)
    {
        if (a[i][m] > max)
        {
            max = a[i][m];
            k = i;
        }
    }
    return k;
}

int Searchmin(int n, int m)
{
    int i, min = 10000;
    int k;
    for (i = 0; i < m; i++)
    {
        if (a[n][i] < min)
        {
            min = a[n][i];
            k = i;
        }
    }
    return k;
}

int main()
{
    int n, m, flag = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = Searchmin(i, m);
        int k = Searchmax(n, j);
        if (i == k)
        {
            printf("%d %d %d\n", i + 1, j + 1, a[i][j]);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("NO");
    return 0;
}