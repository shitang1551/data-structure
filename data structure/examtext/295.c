#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *Init(Node *p)
{
    p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->data = -1;

    return p;
}

Node *Add(Node *p, int d)
{
    Node *q = (Node *)malloc(sizeof(Node));
    q->next = p->next;
    q->data = d;
    p->next = q;
    p = q;
    return p;
}

Node *Mix(Node *p, Node *q)
{
    while (q->next != NULL)
    {
        if (p->next != NULL)
        {
            Node *m = p->next;
            Node *n = q->next;
            if (m->data == n->data)
            {
                p = m;
                q = n;
            }
            else if (m->data > n->data)
            {
                p = Add(p, n->data);
                q = n;
                if (q->next != NULL && m->data <= q->next->data)
                {
                    p = m;
                }
            }
            else if (m->data < n->data)
            {
                while (m->next != NULL && m->next->data <= n->data)
                {
                    p = m;
                    m = m->next;
                }
                // if (m != NULL)
                if (m->data != n->data)
                {
                    p = m;
                    p = Add(p, n->data);
                    q = n;
                }
            }
        }
        else
        {
            q = q->next;
            if (p->data != q->data)
                p = Add(p, q->data);
        }
    }

    return p;
}

Node *Mix(Node *p, Node *q)
{
    Node *f = (Node *)malloc(sizeof(Node));
    f->data = -1;
    f->next = NULL;
    Node *f1 = f;
    p = p->next;
    q = q->next;
    while (p != NULL && q != NULL)
    {

        if (p->data == q->data)
        {
            f = Add(f, p->data);
            p = p->next;
            q = q->next;
        }
        else if (p->data > q->data)
        {
            f = Add(f, q->data);
            q = q->next;
        }
        else if (p->data < q->data)
        {
            f = Add(f, p->data);
            p = p->next;
        }
    }
    while (p != NULL)
    {
        f = Add(f, p->data);
        p = p->next;
    }
    while (q != NULL)
    {
        f = Add(f, q->data);
        q = q->next;
    }
    return f1;
}

void Print(Node *p)
{
    while (p->next != NULL)
    {

        p = p->next;
        printf("%d ", p->data);
    };
    //
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    Node *p, *q, *p1, *q1, *p2;
    p = Init(p);
    q = Init(q);
    p1 = p;
    q1 = q;
    p2 = p;

    for (int i = 0; i < a; i++)
    {
        int t;
        scanf("%d", &t);
        p = Add(p, t);
    }
    for (int i = 0; i < b; i++)
    {
        int t;
        scanf("%d", &t);
        q = Add(q, t);
    }
    // printf("%d ", p2->data);
    // printf("%d ", q1->data);
    p1 = Mix(p1, q1);

    Print(p2);

    return 0;
}