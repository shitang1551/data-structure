#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Stackinitsize 100
#define Stackincement 10
#define Elemtype char

typedef struct 
{
    Elemtype* base;
    Elemtype* top;
    int stacksize;
}Sqstack;

Sqstack Initstack(Sqstack s){
    s.base=(Elemtype *)malloc(Stackinitsize*sizeof(Elemtype));
    if(!s.base)exit(0);
    s.top=s.base;
    s.stacksize=Stackinitsize;
    return s;
}

Elemtype Gettop(Sqstack s,Elemtype e){
    if(s.base==s.top)
    exit(0);
    e=*(s.top-1);
    return e;
}

Sqstack push(Sqstack s,Elemtype e){
    if(s.top-s.base>=s.stacksize){
        s.base=(Elemtype *)realloc(s.base,((s.stacksize+Stackincement)*sizeof(Elemtype)));
        if(!s.base)exit(0);

        s.top=s.base+s.stacksize;
        s.stacksize+=Stackincement;
    }
    *s.top++=e;
    //printf("oo");
    return s;
}

Elemtype e;
Sqstack pop(Sqstack s){
    if(s.base==s.top)exit(0);
    e=*--s.top;
    return s;
}

Sqstack clearstack(Sqstack s){
    s.base=s.top;
    return s;
}

int stackempty(Sqstack s){
    if(s.base==s.top||s.base==NULL)
    return 1;
    else
    return 0;
}

int stackLength(Sqstack s){
    int len;
    len=s.top-s.base;
    return len;
}

void printstack(Sqstack s){
    if(s.base==s.top)exit(0);
    Elemtype* p=s.base;
    while(p!=s.top){
        printf("%d ",*p);
        p++;
    }
}

void conversion(){
    Sqstack s;
    s=Initstack(s);
    int n;
    scanf("%d",&n);
    while(n){
        s=push(s,n%8);
        n=n/8;
    }
    while(!stackempty(s)){
        s=pop(s);
        printf("%d",e);
    }
}

void matchbrackets(){//1->[, 2->], 3->(, 4->)
    Sqstack s=Initstack(s);
    int flag=0;
    
    while(1){
        int c;
        scanf("%d",&c);
        //if(!c)break;
        //printf("oo");
        if(c==1||c==3){
            s=push(s,c);
            //printf("ss");
        }
        else if(c==2||c==4){
            s=pop(s);
            if(e!=c-1){
                flag=1;
                break;
            }
        }
        else break;
    }
    
    if(!stackempty(s))
    flag=1;
    if(flag==1)printf("error");
    else printf("pass");
    //return 0;
}

