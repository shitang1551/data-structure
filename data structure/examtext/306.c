#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SelemType char
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

char Pop(Linkstack s)
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
    char a[100];
    int i = 0;
    scanf("%s", &a);
    Linkstack s = Initstack();
    while (a[i])
    {
        //
        if (a[i] <= '9' && a[i] >= '1')
        {
            Push(s, a[i]);
        }
        else
        {
            char b = Pop(s);
            char c = Pop(s);
            char k;
            if (a[i] == '+')
            {
                k = c + b - '0';
            }
            else if (a[i] == '*')
            {
                k = (c - '0') * (b - '0') + '0';
            }
            else if (a[i] == '-')
            {
                k = c - b + '0';
            }
            else
            {
                k = (c - '0') / (b - '0') + '0';
            }
            Push(s, k);
            // printf("%d ", (int)k);
        }
        i++;
    }
    int m = Pop(s) - '0';
    printf("%d", m);
}