#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define QElemType char
typedef struct Qnode
{
    QElemType data;
    struct Qnode* next;
}Qnode,*QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
}Queue,*LinkQueue;
//有头结点

void InitQueue(LinkQueue q){
    q->front=(QueuePtr)malloc(sizeof(Qnode));
    q->front->next=NULL;
    q->front->data=NULL;
    q->rear=q->front;
}

void ClearQueue(LinkQueue q){

}

int qisempty(LinkQueue q){
    if(q->front==q->rear)return 1;
    return 0;
}

QElemType EnQueue(LinkQueue q,QElemType e){
    QueuePtr p=(QueuePtr)malloc(sizeof(Qnode));
    p->next=NULL;
    p->data=e;
    q->rear->next=p;
    q->rear=p;
    return e;
}

QElemType DeQueue(LinkQueue q,QElemType e){
    QueuePtr p=q->front->next;
    QElemType e=p->data;
    q->front->next=p->next;
    if(q->rear==p)q->rear=q->front;
    free(p);
    return e;
}