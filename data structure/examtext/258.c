#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int Key;
    int Next;
} Node;

// Node n[10000]; //下标为address

void DownLode(Node n[], int m)
{
    for (int i = 1; i <= m; i++)
    {
        int a = 0;
        scanf("%d", &a);
        scanf("%d %d", &n[a].Key, &n[a].Next);
    }
}

void Delete(Node n[], int s, int a)
{
    while (n[s].Next != a)
    {
        s = n[s].Next;
    }
    n[s].Next = n[a].Next;
}

void Print(Node n[], int next)
{
    while (next != -1)
    {
        if (n[next].Next == -1)
        {
            printf("%05d %d -1", next, n[next].Key);
        }
        else
        {
            printf("%05d %d %05d\n", next, n[next].Key, n[next].Next);
        }
        next = n[next].Next;
    }
}

int main()
{
    int m, r;
    Node n[100000];
    scanf("%d%d", &r, &m);
    n[r].Key = m;
    DownLode(n, m);
    for (int i = r; i != -1; i = n[i].Next)
    {
        for (int j = n[i].Next; j != -1; j = n[j].Next)
        {
            if (n[i].Key == n[j].Key || n[i].Key == -n[j].Key)
            {
                Delete(n, r, j);
                m--;
            }
        }
    }
    printf("%d\n", m);
    Print(n, r);
    return 0;
}