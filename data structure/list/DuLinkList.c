#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
//表长是什么i的合法值范围
typedef struct DuLNode
{
    int data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinklist;

DuLinklist GetElemP_DuL(DuLinklist l,int i){
    int j=1;
    DuLinklist m=l->next;
    if(i<=0||i>=Queuemaxsize+1)return NULL;   
    while(j<i&&m!=l){
        m=m->next;
        j++;
    }
    if(m==l)return NULL;
    return m;
}
DuLinklist ListInsert_DuL(DuLinklist l,int i,int e){
    DuLinklist p=GetElemP_DuL(l,i);//i合法值1到表长+1
    if(!p)return NULL;
    DuLinklist s=(DuLinklist)malloc(sizeof(DuLNode));
    if(!s)return NULL;
    s->data=e;
    s->prior=p->prior;
    p->prior->next=s;
    s->next=p;
    p->prior=s;
    return l;
}
DuLinklist ListDelete_DuL(DuLinklist l,int i,int e){
    DuLinklist p=GetElemP_DuL(l,i);//i的合法值1-表长
    if(!p)return NULL;
    e=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
    return l;
}