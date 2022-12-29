#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXVERTEXNUM 20 // V
#define INFINITY 10000
#define VRType
#define InfoType
#define VertexType

typedef struct Arcnode
{
    int adjvex;              //弧尾点
    struct Arcnode *nextarc; //下一个相连的点
    InfoType info;           //权值
} Arcnode;                   //表结点
typedef struct Vnode
{
    VertexType data;            //弧头点
    Arcnode *firstarc;          //第一个结点
} Vnode, AdjList[MAXVERTEXNUM]; //表头结点
typedef struct
{
    AdjList vertices;   //邻接表
    int vexnum, arcnum; //顶点数、边数
    int kind;           //
} ALGraph;

int visited[MAXVERTEXNUM];
void DFS(ALGraph g, int v)
{
    Arcnode *p;
    visited[v] = 1;
    printf("%d", v); //先序
    p = g.vertices[v].firstarc;
    while (p)
    {
        if (visited[p->adjvex] == 0)
            DFS(g, p->adjvex);
        p = p->nextarc;
    }
}
void DFSTraverse(ALGraph g)
{
    int v = 0;
    for (; v < g.vexnum; v++)
        visited[v] = 0;
    for (v = 0; v < g.vexnum; v++)
        if (visited[v] == 0)
            DFS(g, v);
}

#define QElemType int
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
//队列实现广度优先，层次遍历
void BFS(ALGraph g)
{
    int v = 0;
    for (; v < g.vexnum; v++)
    {
        visited[v] = 0;
    }
    LinkQueue q;
    InitQueue(q);
    for (v = 0; v < g.vexnum; v++)
    {
        if (!visited[v])
        {
            visited[v] = 1;
            printf("%d", v);
            EnQueue(q, v);
            while (!qisempty(q))
            {
                int e;
                e = DeQueue(q, e);
                Arcnode *p = g.vertices[e].firstarc;
                while (p)
                {
                    if (!visited[p->adjvex])
                    {
                        visited[p->adjvex] = 1;
                        printf("%d", p->adjvex);
                        EnQueue(q, p->adjvex);
                    }
                    p = p->nextarc;
                }
            }
        }
    }
}