#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
int main()
{
    int n, m, i = 0, j = 0, k1 = 0, k2 = 0, k = 0;
    int b1[100][100], v1[100], b2[100][100], v2[100], b[100][100], v[100];
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &b1[i][j]);
            if (b1[i][j] == 1)
            {
                k1++;
            }
        }
    }

    for (i = 0; i < k1; i++)
        scanf("%d", &v1[i]);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &b2[i][j]);
            if (b2[i][j] == 1)
            {
                k2++;
            }
        }
    }
    for (i = 0; i < k2; i++)
        scanf("%d", &v2[i]);
    // printf("s%ds", k2);
    int p = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (b1[i][j] == 1)
            {
                b1[i][j] = v1[p];
                p++;
            }
        }
    }
    p = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (b2[i][j] == 1)
            {
                b2[i][j] = v2[p];
                p++;
            }
        }
    }
    p = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            int q = b1[i][j] + b2[i][j];
            if (q)
            {
                b[i][j] = 1;
                v[p] = q;
                p++;
            }
            else
                b[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < p; i++)
        printf("%d ", v[i]);
    return 0;
}
