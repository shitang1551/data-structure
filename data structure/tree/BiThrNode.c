#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TElemType
#define Status

typedef struct BiThrNode
{
    TElemType data;
    int LTag, RTag;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
} BiThrNode, *BiThrTree;

//先序线索二叉树
//寻找先序的前驱结点
BiThrTree PreOrderPreNode(BiThrTree p)
{
}

//寻找先序后继结点
BiThrTree PreOderPostNode(BiThrTree p)
{
}

//中序线索二叉树
//寻找中序前驱结点
BiThrTree InOrderPreNode(BiThrTree p)
{
    BiThrNode *pre = p->lchild;
    if (p->LTag == 0)
        while (pre->RTag == 0)
            pre = pre->rchild;
    return pre;
}

//寻找中序后继结点
BiThrTree InOderPostNode(BiThrTree p)
{
    BiThrTree post = p->rchild;
    if (p->RTag == 0)
        while (post->LTag == 0)
            post = post->lchild;
    return post;
}

//后序线索二叉树
//寻找后序的前驱结点
BiThrTree PostOrderPreNode(BiThrTree p)
{
    BiThrTree pre;
    if (p->LTag == 1)
        pre = p->lchild;
    if (p->LTag == 0)
    {
        if (p->RTag == 0)
            pre = p->rchild;
        if (p->RTag == 1)
            pre = p->lchild;
    }
}

//寻找后序的后继结点
BiThrTree PostOrderPostNode(BiThrTree p)
{
    if (p)
    {
    }
}

//建立中序线索化链表

//中序遍历线索二叉树（带头结点）
void InOrderTraverse_Thr(BiThrTree t)
{
    BiThrTree p = t->lchild;
    while (p != t)
    {
        while (p->LTag == 0)
            p = p->lchild;
        while ((p->RTag == 1) && (p->rchild != t))
        {
            p = p->rchild;
        }
        p = p->rchild;
    }
}

//建立中序二叉树
BiThrTree pre;
void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild)
        {
            p->lchild = pre;
            p->LTag = 1;
        }
        else
            p->LTag = 0;
        if (!pre->rchild)
        {
            pre->rchild = p;
            pre->RTag = 1;
        }
        else
            pre->RTag = 0;
        pre = p;
        InThreading(p->rchild);
    }
}
BiThrTree InOrderThreading(BiThrTree th, BiThrTree t)
{
    th = (BiThrTree)malloc(sizeof(BiThrNode)); //头结点
    th->LTag = 0;
    th->RTag = 1;
    th->rchild = th;
    if (!t)
        th->rchild = t;
    else
    {
        th->lchild = t;
        pre = th;
        InThreading(t);
        pre->rchild = th;
        pre->RTag = 1;
        th->rchild = pre;
    }
    return th;
}
