#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SelemType char*
#define Stackmaxz 10

typedef struct Stnode
{
    SelemType data;
    struct Stnode* next;
}Stnode,*Linknode;

typedef struct Stack
{
    Linknode base;
    Linknode top;
}Stack,*Linkstack;

Linknode Initnode(){
    Linknode q=(Linknode)malloc(sizeof(Stnode));
    q->data=NULL;
    q->next=NULL;
    return q;
}

Linkstack Initstack(){
    Linkstack s=(Linkstack)malloc(sizeof(Stack));
    s->base=Initnode();
    s->top=s->base;
    return s;
}

SelemType Gettop(Linkstack s){
    if(s->top==NULL)return NULL;
    return s->top->data;
}

int isempty(Linkstack s){
    if(s->base==s->top)
    return 1;
    else return 0;
}

void Push(Linkstack s,SelemType e){
    Linknode p=(Linknode)malloc(sizeof(Stnode));
    if(p==NULL)exit(0);
    p->next=s->top;
    p->data=e;
    s->top=p;
}

SelemType e;
int Pop(Linkstack s){
    if(isempty(s))return 0;
    Linknode p=s->top;
    e=p->data;
    s->top=p->next;
    free(p);
    return 1;
}

void Clearstackforedit(Linkstack s){
    Linknode q=Initnode();
    while(s->top!=s->base&&s->top->data!='\n'){
        q=s->top;
        s->top=q->next;
        free(q);
        q=Initnode();
    }
}

void edit(){
    Linkstack s=Initstack();
    char ch=0;
    int i=0,j=0;
    while(ch!='$'){//"$"表示结束
        do{
            //ch=getchar();
            scanf("%c",&ch);
            if(ch=='#')
            Pop(s);
            else if(ch=='@')
            Clearstack(s);
            else
            Push(s,ch);
        }while(ch!='\n'&&ch!='$');
    }
    
    Pop(s);
    Linkstack s1=Initstack(); 
    while(!isempty(s)){
        if(Pop(s))
        Push(s1,e);
    }
    while(!isempty(s1)){
        Pop(s1);
        printf("%c",e);
        j++;
    }
}