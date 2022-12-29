#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QElemType char
#define Queuemaxsize 100

typedef struct
{
    QElemType *base;
    int front;
    int rear;
} Queue, *SqQueue;

void InitQueue(SqQueue q)
{
    q->base = (QElemType *)malloc(Queuemaxsize * sizeof(QElemType));
    if (!q->base)
        exit(0);
    q->front = q->rear = 0;
}

void QueueLength(SqQueue q)
{
    return (q->rear - q->front + Queuemaxsize) % Queuemaxsize;
}

int sQisempty(SqQueue q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

int sQisfull(SqQueue q)
{
    if ((q->rear + 1) % Queuemaxsize == q->front)
        return 1;
    else
        return 0;
}

int EnQueue(SqQueue q, QElemType e)
{
    if ((q->rear + 1) % Queuemaxsize == q->front)
        return NULL;
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % Queuemaxsize;
    return 1;
}

QElemType DeQueue(SqQueue q, QElemType e)
{
    if (q->front == q->rear)
        return NULL;
    e = q->base[q->front];
    q->front = (q->front + 1) % Queuemaxsize;
    return e;
}
