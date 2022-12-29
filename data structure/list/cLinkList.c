//链表是否可以定义为null
#include<stdio.h>
#include<stdlib.h>
//为什么结构体定义时标签和变量名都要声明
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Link,*Position;//节点类型

typedef struct 
{
    Link head,tail;//头结点和尾结点
    int len;
}cLinklist;

Link MakeNode(Link p,int e){
    p->data=e;
    if(p)
    return p;
    else
    return 0;
}

Link FreeNode(Link p){
    if(p->next)
    {
        Link h=p->next;
        p->next=h->next;
        return h;
    }
    else
    {p->next=NULL;
    return p;}
}

//无法返回l
int InitList(cLinklist l){
    l.head=(Link)malloc(sizeof(LNode));
    l.tail=(Link)malloc(sizeof(LNode));
    if(!l.head&!l.tail){
        return 0;
    }
    l.head->next=NULL;
    l.tail->next=NULL;
    l.len=0;
    return 1;
}

cLinklist DestroyList(cLinklist l){
    l.head=NULL;
    l.tail=NULL;
    l.len=0;
    return l;
}

cLinklist ClearList();

void InsFirst(Link h,Link s){
    s->next=h->next->next;
    h->next=s;
}//返回空类型是否可以形成全新的顺序结构

Link DelFirst(Link h,Link q){
    q=h->next;
    h->next=q->next;
    return q;
}

cLinklist Append(cLinklist l,Link s){
   l.tail->next=s;
   return l;
}

cLinklist Remove(cLinklist l,Link q){
    Link s=(Link)malloc(sizeof(LNode));
    Link m=l.head;
    q=l.tail;
    while(l.head->next!=l.tail){
        l.head=l.head->next;
    }
    l.head->next=s;
    l.head=m;
    return l;
}

cLinklist InsBefore(cLinklist l,Link p,Link s){
    Link k=l.head;
    while(l.head->next!=p&&l.head->next)
    l.head=l.head->next;
    l.head->next=s;
    s->next=p;
    l.head=k;
    return l;
}

cLinklist InsAfter(cLinklist l,Link p,Link s){
    s->next=p->next;
    p->next=s;
    return l;
}

void SetCutElem(Link p,int e){
    p->data=e;
}

int GetCurElem(Link p){
    return p->data;
}

int ListEmpty(cLinklist l){
    if(l.head->next==NULL)
    return 0;
    else
    return 1;
}

int ListLength(cLinklist l){
    return l.len;
}

int GetHead(cLinklist l){
    return 1;
}

int GetLast(cLinklist l){
    int i=0;
    Link m=l.head;
    while(l.head->next!=l.tail){
        l.head=l.head->next;
        i++;  
    } 
    l.head=m;
    return i;
}

int PriorPos(cLinklist l,Link p){
    if(l.head==p)
    return 0;
    int i=1;
    while(l.head->next!=p)
    {l.head=l.head->next;i++;}
    return i;
}

int NextPos(cLinklist l,Link p){
    if(p==l.tail)
    return 0;
    int i=1;
    while(l.head->next!=p)
    {l.head=l.head->next;i++;}
    return i+2;
}

Link LocatePos(cLinklist l,int i,Link p){
    if(i>l.len)
    return 0;
    for(int j=0;j<i;j++){
        l.head=l.head->next;
    }
    p=l.head;
    return p;
}

int compare(int x,int y){
    if(x==y)
    return 1;
    else 
    return 0;
}
int LocateElem(cLinklist l,int e,int(*compare)(int,int)){
    int i=1;
    while(!(*compare)(l.head->data,e)&&l.head->next!=NULL){
        l.head=l.head->next;
        i++;
    }
    if(l.head->next==NULL)
    return 0;
    else
    return i;
}

int visit(){

}
int ListTraverse(){

}

//具体使用
int ListInsert_L(cLinklist l,int i,int e){
    Link h;
    if(!LocatePos(l,i-1,h)) return 0;
    Link s;
    if(!MakeNode(s,e))return 0;
    InsFirst(h,s);
    return 1;
}

int compare(int a,int b){
    if(a==b)return 0;
    if(a<b)return -1;
    if(a>b)return 1;
}
cLinklist MergeList_L(cLinklist la,cLinklist lb,cLinklist lc){
    lc.head=NULL;
    lc.tail=NULL;
    lc.len=NULL;
    if (!InitList(lc))return lc;
    int ha=GetHead(la);
    int hb=GetHead(lb);
    Link pa=NextPos(la,ha);
    Link pb=NextPos(lb,hb);
    while(pa&&pb){
        int a=GetCurElem(pa);
        int b=GetCurElem(pb);
        if((*compare)(a,b)<=0){
            Link q;
            DelFirst(ha,q);
            Append(lc,q);
            pa=NextPos(la,ha);
        }
        else{
            Link q;
            DelFirst(hb,q);
            Append(lc,q);
            pa=NextPos(lb,hb);
        }
    }
    if(pa)Append(lc,pa);
    else Append(lc,pb);
    FreeNode(ha);
    FreeNode(hb);
    return lc;
}

