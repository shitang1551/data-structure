#include <string.h>
#include <string.h>
#include <stdlib.h>
#define MAXTREESIZE 100
#define TElemType

//双亲表示法
typedef struct PTNode
{
    TElemType data;
    int parent;
} PTNode;
typedef struct
{
    PTNode nodes[MAXTREESIZE];
    int r, n;
} PTree;
