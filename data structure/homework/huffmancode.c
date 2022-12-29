#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//哈夫曼
typedef struct HTNode
{
    int weight;
    int parent, lchild, rchild;
    int flag;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode; //编码

int Min(HuffmanTree t, int a)
{
    int s = 0, min = 100;
    for (int i = 1; i <= a; i++)
    {
        if (t[i].flag == 0 && t[i].parent == 0)
            if (t[i].weight < min)
            {
                min = t[i].weight;
                s = i;
            }
    }
    t[s].flag = 1;
    // printf("o%do", s);
    return s;
}

HuffmanTree HuffmanCoding(HuffmanTree t, int *w, int n)
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
        p->flag = 0;
        p->weight = *w;
    }
    for (; i <= m; i++)
    {
        p->lchild = 0;
        p->parent = 0;
        p->rchild = 0;
        p->flag = 0;
        p->weight = 0;
    }
    for (i = n + 1; i <= m; i++)
    {
        int s1 = Min(t, i - 1);
        int s2 = Min(t, i - 1);
        t[s1].parent = i;
        t[s2].parent = i;
        t[i].lchild = s1;
        t[i].rchild = s2;
        t[i].weight = t[s1].weight + t[s2].weight;
        t[i].parent = 0;
        t[i].flag = 0;
    }
    return t;
}

int Depth(HuffmanTree t, int m)
{
    int i = 0;
    for (; t[m].parent != 0; i++)
    {

        m = t[m].parent;
    }
    return i;
}

int WPL(HuffmanTree t, int n)
{
    int wpl = 0;
    int i = 1;
    for (; i <= n; i++)
    {

        wpl += Depth(t, i) * t[i].weight;
    }

    return wpl;
}

int main()
{
    int n;
    scanf("%d", &n);
    int w[100] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    HuffmanTree t;
    t = HuffmanCoding(t, w, n);

    int wpl = WPL(t, n);
    printf("%d", wpl);
    return 0;
}