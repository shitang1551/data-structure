#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXVERTEXNUM 20 // V
#define INFINITY 10000
#define VRType int
#define InfoType int
#define VertexType int

typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GraphKind;
typedef struct ArcCell
{
    VRType adj; //权值
    InfoType *info;
} ArcCell, AdjMatrix[MAXVERTEXNUM][MAXVERTEXNUM];
typedef struct MGraph
{
    VertexType vexs[MAXVERTEXNUM]; //顶点向量
    AdjMatrix arcs;                //邻接矩阵
    int vexnum, arcnum;            //顶点数、弧数
    // GrapgKind kind;
} MGraph;
struct
{
    int adjvex;     //较早加入边的端点
    double lowcost; //权
} closedge[MAXVERTEXNUM];

int visited[MAXVERTEXNUM];
void DFS(MGraph g, int v)
{
    visited[v] = 1;
    for (int w = 0; w < g.vexnum; w++)
    {
        if (g.arcs[v][w].adj != 0 && visited[w] != 0)
            DFS(g, w);
    }
}
void DFSTraverse(MGraph g)
{
    int v;
    for (; v < g.vexnum; v++)
    {
        visited[v] = 0;
    }
    for (v = 0; v < g.vexnum; v++)
    {
        if (visited[v] == 0)
            DFS(g, v);
    }
}

void MiniSpanTree_Prim(MGraph g, VertexType u)
{

    int k;
    k = LocateVex(g, u);
    for (int j = 0; j < g.vexnum; j++)
    {
        if (j != k)
        {
            closedge[j].adjvex = u;
            closedge[j].lowcost = g.arcs[k][j].adj;
        }
        closedge[k].lowcost = 0;
    }
}
