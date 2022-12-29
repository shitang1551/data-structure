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
    gets(a);
    // int l = strlen(a);
    Linkstack s = Initstack();
    int i = 0, f = 0;

    while (a[i])
    {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{')
        {

            Push(s, a[i]);
        }
        else if (a[i] == ')')
        {
            if (Pop(s) != '(')
            {
                f = 1;
                break;
            }
        }
        else if (a[i] == ']')
        {
            if (Pop(s) != '[')
            {
                f = 1;
                break;
            }
        }
        else if (a[i] == '}')
        {
            if (Pop(s) != '{')
            {
                f = 1;
                break;
            }
        }
        i++;
    }
    //
    if (!isempty(s))
        f = 1;
    if (f == 1)
        printf("wrong");
    else
        printf("right");
    return 0;
}