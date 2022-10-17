#include<stdio.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct{
    int *elem;
    int length;
    int listsize;
}Sqlist;

Sqlist InitList_Sq(Sqlist l){
    l.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!l.elem)
    exit(0);
    l.length=0;
    l.listsize=LIST_INIT_SIZE;
    return l;
}

Sqlist Destroy_Sq(Sqlist l){
    free(l);
}

int ListEmpty_Sq(Sqlist l){
    if(l.length==0)
    return 0;
    else 
    return 1;
}

int ListLength_Sq(Sqlist l){
    return l.length;
}

int GetElem1(Sqlist l,int i){
    if(i<0||i>l.length-1)
    return 0;
    return l.elem[i];
}
int GetElem2(Sqlist l,int i){
    if(i<0||i>l.length-1)
    return 0;
    return l.elem+i;
}

Sqlist ListInsert_Sq1(Sqlist l,int i,int e){
    if(i<1||i>l.length+1)
    return l;
    if(l.length>=l.listsize){
        int* newbase;
        newbase=(int*)relloc(l.elem,l.listsize+LISTINCREMENT*sizeof(int));
        if(!newbase)
        exit(0);
        l.elem=newbase;
        l.listsize+=LISTINCREMENT;
    }
    for(int j=l.length-1;j>=i;j--)
    l.elem[j+1]=l.elem[j];
    l.elem[i-1]=e;
    l.length++;
    return l;
}
Sqlist ListInsert_Sq2(Sqlist l,int i,int e){
    if(i<1||i>l.length+1)
    return l;
    if(l.length>=l.listsize){
        int* newbase;
        newbase=(int*)relloc(l.elem,l.listsize+LISTINCREMENT*sizeof(int));
        if(!newbase)
        exit(0);
        l.elem=newbase;
        l.listsize+=LISTINCREMENT;
    }
    int *q=&(l.elem[i-1]);
    for(int* p=l.elem[l.length-1];p>=q;--p)
    *(p+1)=*p;
    *q=e;
    l.length++;
    return l;
}
Sqlist ListInsert_Sq3(Sqlist l,int i,int e){
    if(i<1||i>l.length+1)
    return l;
    if(l.length>=l.listsize){
        int* newbase;
        newbase=(int*)relloc(l.elem,l.listsize+LISTINCREMENT*sizeof(int));
        if(!newbase)
        exit(0);
        l.elem=newbase;
        l.listsize+=LISTINCREMENT;
    }
    int *q=l.elem+i-1;
    for(int* p=l.elem+l.length-1;p>=q;--p)
    *(p+1)=*p;
    *q=e;
    l.length++;
    return l;
}

int e=NULL;
Sqlist ListDelete_Sq1(Sqlist l,int i){
    if(i<1||i>l.length+1)
    return l;
    e=l.elem[i-1];
    for(int j=i;j<l.length-1;j++)
    l.elem[j]=l.elem[j+1];
    l.length--;
    return l;
}
Sqlist ListDelete_Sq2(Sqlist l,int i){
    if(i<1||i>l.length+1)
    return l;
    int* q=&(l.elem[i-1]);
    e=*q;
    for(;q<&(l.elem[l.length-1]);q++)
    *q=*(q+1);
    l.length--;
    return l;
}
Sqlist ListDelete_Sq3(Sqlist l,int i){
    if(i<1||i>l.length+1)
    return l;
    int* q=l.elem+i-1;
    for(;q<l.elem+l.length-1;q++)
    *q=*(q+1);
    l.length--;
    return l;
}

Sqlist MergeList_Sq(Sqlist la,Sqlist lb,Sqlist lc){
    int* pa=la.elem;
    int* pb=lb.elem;
    int* pc=NULL;
    lc.listsize=la.length+lb.length;
    lc.length=lc.listsize;
    if(!lc.elem)exit(0);
    while(pa<la.elem+la.length&&pb<lb.elem+lb.length){
        if(*pa<=*pb)
        *pc++=*pa++;
        else
        *pc++=*pb++;
    }
    while(pa<la.elem+la.length)
    *pc++=*pa++;
    while(pb<lb.elem+lb.length)
    *pc++=*pb++;
    return lc;
}
