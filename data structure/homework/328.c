#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Search(int a[], int s)
{
    int i = 0;
    while (a[i] != -2)
    {
        if (s == a[i])
            return i;
        i++;
    }
    return -1;
}

int main()
{
    int m, p;
    scanf("%d%d", &m, &p);
    int a[100], k = -1, sum = 0, t, f;
    for (int i = 0; i < m; i++)
        a[i] = -1;
    for (int i = m; i < 100; i++)
        a[i] = -2;
    do
    {
        scanf("%d", &k);
        if (k == -1)
            return 0;
        t = k % p;
        f = Search(a, k);
        if (f != -1)
        {
            printf("%d\n", f);
        }
        else
        {
            if (sum == m - 1)
            {
                printf("Table full");
                return 0;
            }
            else
            {
                while (a[t] != -1)
                {
                    t++;
                }
                a[t] = k;
                printf("%d\n", t);
                sum++;
            }
        }
    } while (k != -1);
}