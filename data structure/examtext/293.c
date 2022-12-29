#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{
    int num;
    struct Node *next;
} Node, *Queue;

typedef struct SQueue
{
    Node *first;
    Node *last;
    int length;
} SQueue;

void Init(SQueue *s)
{
    //初始化要分配空间
    s->first = (Queue)malloc(sizeof(Node));
    s->first->next = NULL;
    s->first->num = 1;
    s->last = s->first;
    s->length = 1;
}

void EnQueue(SQueue *s, int i)
{
    Queue m = (Queue)malloc(sizeof(Node));
    m->num = i;
    m->next = NULL;
    s->last->next = m;
    s->last = m;
    s->length++;
}

int DeQueue(SQueue *s)
{
    int k = s->first->num;
    s->first = s->first->next;
    s->length--;
    return k;
}

int isempty(SQueue *s)
{
    if (s->length == 0)
        return 1;
    else
        return 0;
}

void De(SQueue *s, int w)
{
    Queue p = s->last;
    int i = 1;
    int l = s->length;
    while (i <= l)
    {
        int k = DeQueue(s);
        if (i % w != 0)
            EnQueue(s, k);
        i++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    SQueue *s = (SQueue *)malloc(sizeof(SQueue));
    Init(s);

    for (int i = 2; i <= n; i++)
    {
        EnQueue(s, i);
    }
    if (n > 3)
    {
        while (1)
        {
            De(s, 2);
            if (s->length <= 3)
                break;
            De(s, 3);
            if (s->length <= 3)
                break;
        }
    }

    while (!isempty(s))
        printf("%d ", DeQueue(s));

    return 0;
}