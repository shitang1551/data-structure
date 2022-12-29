#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SelemType int
#define Stackmaxz 10
typedef struct Stnode
{
    SelemType data;
    struct Stnode *next;
} Stnode, *Linknode;

typedef struct Stack
{
    Linknode base;
    Linknode top;
} Stack, *Linkstack;

Linkstack Push(Linkstack s, SelemType e)
{
    Linknode p = (Linknode)malloc(sizeof(Stnode));
    if (p == NULL)
        exit(0);
    p->next = s->top;
    p->data = e;
    s->top = p;
    return s;
}
Linknode Initnode()
{
    Linknode q = (Linknode)malloc(sizeof(Stnode));
    q->data = NULL;
    q->next = NULL;
    return q;
}
Linkstack Initstack()
{
    Linkstack s = (Linkstack)malloc(sizeof(Stack));
    s->base = Initnode();
    s->top = s->base;
    return s;
}

SelemType e;
int isempty(Linkstack s)
{
    if (s->base == s->top)
        return 1;
    else
        return 0;
}

int Pop(Linkstack s)
{
    if (isempty(s))
        return 0;
    Linknode p = s->top;
    e = p->data;
    s->top = p->next;
    free(p);
    return e;
}

int main()
{
    int n, i, j, k;
    int a[10];
    a[0] = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    Linkstack s = Initstack();
    i = 1;
    j = 0;
    k = 1;
    int e = 0;
    while (i != n)
    {
        if (a[i] > a[j])
        {
            for (; k <= a[i]; k++)
            {
                s = Push(s, k);
            }
            Pop(s);
            i++;
            j++;
        }
        else
        {
            int m = Pop(s);
            if (a[i] != m)
            {
                e = 1;
                break;
            }
            i++;
            j++;
        }
    }
    if (!e)
        printf("yes");
    else
        printf("no");
    return 0;
}