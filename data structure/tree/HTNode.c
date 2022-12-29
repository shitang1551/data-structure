#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//哈夫曼
typedef struct HTNode
{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode; //编码

HuffmanTree HuffmanCoding(HuffmanTree t, HuffmanCode c, int *w, int n)
{
    int m = 2 * n - 1;
    t = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    HTNode *p = t + 1;
    int i = 1;
    for (; i <= n; i++, p++, w++)
    {
        p->lchild = 0;
        p->parent = 0;
        p->rchild = 0;
        p->weight = *w;
    }
    for (; i <= m; i++)
    {
        p->lchild = 0;
        p->parent = 0;
        p->rchild = 0;
        p->weight = 0;
    }
    for (i = n + 1; i <= m; i++)
    {
        Select(t, i - 1);
        t[s1].parent = i;
        t[s2].parent = i;
        t[i].lchild = s1;
        t[i].rchild = s2;
        t[i].weight = t[s1].weight + t[s2].weight;
    }
}

int s1, s2;
void Select(HuffmanTree t, int a)
{
    int i;
    int min1 = 100, min2 = 100;
    for (i = 1; i <= a; i++)
    {
        if (t[i].weight < min1)
        {
            min1 = t[i].weight;
            s1 = i;
        }
    }
    for (i = 1; i <= a; i++)
    {
        if (i != s1)
            if (t[i].weight < min2)
            {
                min2 = t[i].weight;
                s2 = i;
            }
    }
    /*t[s1].weight=100;
    t[s2].weight=100;*/
}