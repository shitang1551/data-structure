#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Gnode
{
    int num;
    Gnode *next;
} Gnode;

typedef struct Graph
{
    Gnode *first;
    Gnode *cur;
    int flag;
} Graph;

int coal[30], j = 0;
Graph arc[30];

void DFS(int v)
{
    arc[v].flag = 1;
    coal[j]++;
    Gnode *k = arc[v].first;
    // printf("%d-", k->num);
    while (k)
    {
        if (arc[k->num].flag == 0)
        {
            DFS(k->num);
        }
        k = k->next;
    }
}

int main()
{
    int m, n, i, a, b, p, q;
    scanf("%d%d", &n, &m);

    for (i = 1; i <= n; i++)
    {
        Gnode *k = (Gnode *)malloc(sizeof(Gnode));
        k->num = i;
        k->next = NULL;
        arc[i].cur = k;
        arc[i].first = arc[i].cur;
        arc[i].flag = 0;
    }

    for (i = 0; i < m; i++)
    {
        Gnode *k = (Gnode *)malloc(sizeof(Gnode));
        scanf("%d%d", &a, &b);
        k->num = b;
        k->next = NULL;
        arc[a].cur->next = k;
        arc[a].cur = k;
    }

    for (i = 1; i <= n; i++)
    {
        if (arc[i].flag == 0)
        {
            coal[j] = 0;
            DFS(i);
            j++;
        }
    }
    printf("%d\n", j);
    for (p = 0; p < j - 1; p++)
        for (q = 0; q < j - p - 1; q++)
        {
            if (coal[q] > coal[q + 1])
            {
                b = coal[q];
                coal[q] = coal[q + 1];
                coal[q + 1] = b;
            }
        }
    for (i = 0; i < j; i++)
        printf("%d ", coal[i]);
    return 0;
}