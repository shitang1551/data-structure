#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int arc[30][30];
int visit[30][30];
int visit_1[30][30];
int i, j, m, n, a, b, p, min, s, q, k, v, w, t, d, ans;
typedef struct Vex
{
    int num;
    int elem;
} Vex;

Vex du[30];

void Findmin()
{
    min = 100;
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (visit[i][j] == 0)
                if (arc[i][j] < min)
                {
                    a = i;
                    b = j;
                    min = arc[i][j];
                }
        }
    }
    visit[a][b] = 1;
}

void reCircle()
{
    for (i = 1; i <= n; i++)
    {
        du[i].num = 0;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (visit_1[i][j] == 1)
            {
                du[i].num++;
                du[i].elem = j;
                du[j].num++;
                du[j].elem = i;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (du[i].num == 1)
        {
            j = du[i].elem;
            // printf("%d`%d\n", i, j);
            visit_1[i][j] = 0;
            visit_1[j][i] = 0;
            break;
        }
    }
}

int has1(int stand)
{
    for (i = 1; i <= n; i++)
    {
        if (du[i].num == stand)
            return 1;
    }
    return 0;
}

int hasCircle()
{
    int flag = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            visit_1[i][j] = visit[i][j];
        }
    }
    do
    {
        reCircle();
    } while (has1(1));

    return has1(2);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            arc[i][j] = 100;
            visit[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &j);
        arc[a][b] = j;
    }
    for (p = 1; p < n; p++)
    {
        do
        {
            // printf("oo");
            Findmin();
            ans = hasCircle();
            // printf("%d-%d:%d \n", a, b, ans);
            if (!ans)
                break;
            else
                visit[a][b] = 2;
        } while (1);
        printf("%d %d %d\n", a, b, arc[a][b]);
    }
    return 0;
}