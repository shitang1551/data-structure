#include<stdio.h>
typedef struct{
    int data;
    struct Lnode *next;
}Lnode,*Linklist;

//带头结点
Linklist InitList(Linklist l){
    l=(Linklist)malloc(sizeof(Lnode));
    l->next=NULL;
    return l;
}

Linklist CreatList1(Linklist l,int n){
    l=(Linklist)malloc(sizeof(Lnode));
    l->next=NULL;
    for(int i=0;i<n;i++){
        Linklist e=(Linklist)malloc(sizeof(Lnode));
        scanf("%d",&e->data);
        e->next=l->next;
        l->next=e;//头插法       
    }
    return l;
}
Linklist CreatList2(Linklist l,int n){
    l=(Linklist)malloc(sizeof(Lnode));
    l->next=NULL;
    Linklist p=l;
    for(int i=0;i<n;i++){
        Linklist e=(Linklist)malloc(sizeof(Lnode));
        scanf("%d",&e->data);
        e->next=NULL;
        p->next=e; 
        p=e;      //尾插法
    }
    return l;
}

void DestroyList(Linklist l){
    Linklist p=l;
    Linklist q=p->next;
    while(q!=NULL){
        free(q);
        p=q;
        q=p->next;
    }
    free(p);
}

int ListEmpty(Linklist l){
    return l->next!=NULL;
}

int ListLength(Linklist l){
    int i=0;
    Linklist p=l;
    while(p->next!=NULL){
        p=p->next;
        i++;
    }
    return i;
}

void DisplayList(Linklist l){
    Linklist p=l->next;
    while(p!=NULL){
        printf("%c",(*p).data);
        p=p->next;
        printf('\n');
    }
}

int GetElemList(Linklist l,int i){
    Linklist p=l->next;
    int j=1;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if(!p||j>i)return NULL;
    return p->data;
}

Linklist ListInsert(Linklist l,int i,int e){
    Linklist k;
    k->data=i;
    k=(Linklist)malloc(sizeof(Lnode));
    Linklist p=l->next;
    int j=1;
    while(p&&j<i){
        p=p->next;
        j++;
    }    
    if(!p||j>i)return NULL;
    k->next=p->next;
    p->next=k;
    return l;
}

Linklist ListDelete(Linklist l,int i){
    Linklist p=l->next;
    int j=1;
    while(p&&j<i){
        p=p->next;
        j++;
    }    
    if(!p->next||j>i)return NULL;
    Linklist q=p->next;
    p->next=q->next;
    free(q);
    return l;
}

int LocateElem(Linklist l,int e){
    Linklist p=l->next;
    int n=1;
    while(p&&p->data!=e){
        p=p->next;
        n++;
    }
    if(!p)return NULL;
    return n;
}

Linklist MergeList(Linklist la,Linklist lb,Linklist lc){
    Linklist pa=la->next;
    Linklist pb=lb->next;
    Linklist pc=la;
    lc=pc;
    while(pa&&pb)
    {
        if(pa->data<pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else{
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
    free(lb);
    return lc;
}