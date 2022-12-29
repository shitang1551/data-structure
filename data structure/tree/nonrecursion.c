#include <stdio.h>
#include <string.h>
#define TElemType int
#define Status int
#define OK 1
#define ERROR 0

typedef Status (*Visit)(TElemType);
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct BiTree
{
};

//栈
#define SelemType BiTree
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

SelemType Gettop(Linkstack s)
{
    if (s->top == NULL)
        return NULL;
    return s->top->data;
}

int isempty(Linkstack s)
{
    if (s->base == s->top)
        return 1;
    else
        return 0;
}

void Push(Linkstack s, SelemType e)
{
    Linknode p = (Linknode)malloc(sizeof(Stnode));
    if (p == NULL)
        exit(0);
    p->next = s->top;
    p->data = e;
    s->top = p;
}

SelemType e;
int Pop(Linkstack s)
{
    if (isempty(s))
        return 0;
    Linknode p = s->top;
    e = p->data;
    s->top = p->next;
    free(p);
    return 1;
}

//队列
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QElemType BiTree
typedef struct Qnode
{
    QElemType data;
    struct Qnode *next;
} Qnode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} Queue, *LinkQueue;
//有头结点

void InitQueue(LinkQueue q)
{
    q->front = (QueuePtr)malloc(sizeof(Qnode));
    q->front->next = NULL;
    q->front->data = NULL;
    q->rear = q->front;
}

void ClearQueue(LinkQueue q)
{
}

int qisempty(LinkQueue q)
{
    if (q->front == q->rear)
        return 1;
    return 0;
}

QElemType EnQueue(LinkQueue q, QElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(Qnode));
    p->next = NULL;
    p->data = e;
    q->rear->next = p;
    q->rear = p;
    return e;
}

QElemType DeQueue(LinkQueue q, QElemType e)
{
    QueuePtr p = q->front->next;
    QElemType e = p->data;
    q->front->next = p->next;
    if (q->rear == p)
        q->rear = q->front;
    free(p);
    return e;
}

//树

Status Visit(TElemType e)
{
}

Status PrintElem(TElemType e)
{
    printf("%d", e);
    return OK;
}

// pre
//非递归
Status PreOrderTraverse3(BiTree t, Status (*Visit)(TElemType))
{
    Linkstack s = Initstack();
    Push(s, t);
    while (!isempty(s))
    {
        Pop(s);
        if (e->rchild)
            Push(s, e->rchild);
        if (e->lchild)
            Push(s, e->lchild);
    }
}
Status PreOrderTraverse4(BiTree t, Status (*Visit)(TElemType))
{
}

// in
//非递归(栈)
Status InOrderTraverse3(BiTree t, Status (*Visit)(TElemType))
{
    Linkstack s = Initstack();
    BiTree p = t;
    while (p || !isempty(s))
    {
        if (p)
        {
            Push(s, p);
            p = p->lchild;
        }
        else
        {
            Pop(s);
            p = e;
            p = p->rchild;
        }
    }
}
Status InOrderTraverse4(BiTree t, Status (*Visit)(TElemType))
{
    Linkstack s = Initstack();
    BiTree p;
    while (!isempty(s))
    {
        while (p = Gettop(s))
            Push(s, p->lchild);
        Pop(s); //空指针退栈
        if (!isempty(s))
        {
            Pop(s);
            if (!Visit(p->data))
                return ERROR;
            Push(s, p->rchild);
        }
    }
    return OK;
}

// post
Status PostOrderTraverse(BiTree t, Status (*Visit)(TElemType))
{
}

// level
Status LevelOrderTraverse(BiTree t, Status (*Visit)(TElemType))
{
    LinkQueue q;
    InitQueue(q);
    BiTree b = (BiTree)malloc(sizeof(BiTNode));
    if (t)
        EnQueue(q, t);
    while (!qisempty(q))
    {
        b = DeQueue(q, b);
        if (b->lchild)
            EnQueue(q, b->lchild);
        if (b->rchild)
            EnQueue(q, b->rchild);
    }
}