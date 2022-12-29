#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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
    char k[100];
    int a[100];
    int i = 0, j = 0;
    gets(k);
    i = strlen(k) - 1;

    for (; i >= 0;)
    {
        if (k[i] != ' ')
        {
            if (k[i] == '+' || k[i] == '-' || k[i] == '*' || k[i] == '/')
            {
                a[j] = k[i];
                j++;
                i--;
            }
            else
            {
                int m = 0, c = 0;
                while (i >= 0 && k[i] != ' ')
                {
                    c += (k[i] - '0') * pow(10, m);
                    m++;
                    i--;
                }
                // ;
                a[j] = c + '0';

                j++;
            }
            // printf("%d ", a[j - 1]);
        }
        else
            i--;
    }
    a[j] = NULL;
    i = 0;
    Linkstack s = Initstack();
    while (a[i])
    {
        // printf("%d- ", a[i]);
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            int c = Pop(s);
            int b = Pop(s);
            int k;
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
            // printf("%d%c%d=%d ", c, a[i], b, (int)k);
        }
        else
        {
            Push(s, a[i]);
        }
        i++;
    }
    int m = Pop(s) - '0';
    printf("%d", m);
    return 0;
}