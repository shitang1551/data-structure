#include<stdio.h>
#define MAXSIZE 100
typedef struct{
    int data;
    int cur;
}component,SLinklist[MAXSIZE];

void InitSpace_SL(SLinklist l){
    for(int i=0;i<MAXSIZE-1;i++)
        l[i].cur=i+1;
    l[MAXSIZE-1].cur=0;
}

int Malloc_SL(SLinklist l){
    int i=l[0].cur;
    if(l[0].cur)
    l[0].cur=l[i].cur;
    return i;
}

void Free_SL(SLinklist l,int k){
    l[k].cur=l[0].cur;
    l[0].cur=k;//头插法
}

void Insert_SL(SLinklist l,int i,int r){
    l[i].cur=l[r].cur;
    l[r].cur=i;
}

void Delete_SL(SLinklist l,int p,int k){
    l[p].cur=l[k].cur;
    Free_SL(l,k);
}

int LocateElem_SL(SLinklist l,int e){
    int i=l[0].cur;
    while(i&&l[i].data!=e)
    i=l[i].cur;
    return i;
}

//(A-B)U(B-A)
int difference(int l){
    SLinklist S;
    InitSpace_SL(S);
    l=Malloc_SL(S);
    int r=l;
    int m,n;
    scanf("%D%D",&m,&n);
    for(int j=1;j<=m;j++){
        int i=Malloc_SL(S);
        scanf("%d",&S[i].data);
        S[r].cur=i;
        r=i;//尾插法
    }
    S[r].cur=0;
    for(int j=1;j<=n;j++){
        int b;
        scanf("%d",&b);
        int p,k;
        p=l;
        k=S[l].cur;
        while(k!=S[r].cur&&S[k].data!=b){
            p=k;
            k=S[k].cur;
        }   
        if(k==S[r].cur){
            int i=Malloc_SL(S);
            S[i].data=b;
            S[i].cur=S[r].cur;
            S[r].cur=i;
        }
        else{
            S[p].cur=S[k].cur;
            Free_SL(S,k);
            if(r==k)
                r=p;
        }
    }
}