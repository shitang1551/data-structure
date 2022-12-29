#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{
    int num;
    struct Node *next;
} Node;

void Devide(Node *p, Node *q, int n)
{
    int f = 0;
    if (n % 2 == 0)
        n = n / 2;
    else
    {
        f = 1;
        n = (n - 1) / 2;
    }
    for (int i = 1; i <= n; i++)
    {
        Node *m = (Node *)malloc(sizeof(Node));
        Node *k = (Node *)malloc(sizeof(Node));
        scanf("%d %d", &m->num, &k->num);
        m->next = NULL;
        k->next = NULL;
        p->next = m;
        q->next = k;
        p = m;
        q = k;
    }
    if (f == 1)
    {
        Node *k = (Node *)malloc(sizeof(Node));
        scanf("%d", &k->num);
        k->next = NULL;
        p->next = k;
        p = k;
    }
}

void Print(Node *p, Node *q)
{
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d ", p->num);
    }
    while (q->next != NULL)
    {
        q = q->next;
        printf("%d ", q->num);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Node *p = (Node *)malloc(sizeof(Node)), *q = (Node *)malloc(sizeof(Node));
    p->num = NULL;
    p->next = NULL;
    q->next = NULL;
    q->num = NULL;
    Devide(p, q, n);
    Print(p, q);
    return 0;
}