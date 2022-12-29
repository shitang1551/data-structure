#include <stdio.h>
#include <string.h>
#define TElemType int
#define Status int
#define OK 1
#define ERROR 0
typedef Status (*Visit)(TElemType);
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct BiTree
{
};

Status preCreatBiTree()
{
    BiTree t = (BiTree)malloc(sizeof(BiTNode));
    char n;
    scanf("%c", &n);
    if (n != ' ')
    {
        t->data = n;
        t->lchild = CreatBiTree1();
        t->rchild = CreatBiTree1();
        // return t;
    }
    else if (n == ' ')
        return NULL;
}
Status CreatBiTree(BiTree t)
{
    char n;
    scanf("%c", &n);
    if (n == ' ')
        t = NULL;
    else
    {
        if (!(t = (BiTree)malloc(sizeof(BiTNode))))
            exit(0);
        t->data = n;
        CreatBiTree2(t->lchild);
        CreatBiTree2(t->rchild);
    }
    return OK;
}

Status Visit(TElemType e)
{
}

Status PrintElem(TElemType e)
{
    printf("%d", e);
    return OK;
}

// pre递归
Status PreOrderTraverse1(BiTree t, Status (*Visit)(TElemType))
{
    if (t)
    {
        if (Visit(t->data))
            if (PreOrderTraverse1(t->lchild, Visit))
                if (PreOrderTraverse1(t->rchild, Visit))
                    return ERROR;
    }
    else
        return OK;
}
Status PreOrderTraverse2(BiTree t, Status (*Visit)(TElemType))
{
    if (t)
    {
        if (t != NULL)
        {
            PreOrderTraverse2(t->lchild, Visit);
            PreOrderTraverse2(t->rchild, Visit);
        }
    }
}
//非递归
Status PreOrderTraverse3(BiTree t, Status (*Visit)(TElemType))
{
}
Status PreOrderTraverse4(BiTree t, Status (*Visit)(TElemType))
{
}

// in递归
Status InOrderTraverse1(BiTree t, Status (*Visit)(TElemType))
{
}
Status InOrderTraverse2(BiTree t, Status (*Visit)(TElemType))
{
}
//非递归(栈)
Status InOrderTraverse3(BiTree t, Status (*Visit)(TElemType))
{
}
Status InOrderTraverse4(BiTree t, Status (*Visit)(TElemType))
{
}

// post
Status PostOrderTraverse(BiTree t, Status (*Visit)(TElemType))
{
}

// level
Status LevelOrderTraverse(BiTree t, Status (*Visit)(TElemType))
{
}