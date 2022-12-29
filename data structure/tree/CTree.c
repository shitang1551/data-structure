#include <string.h>
#include <string.h>
#include <stdlib.h>
#define MAXTREESIZE 100
#define TElemType

typedef struct CTNode
{
    int Child;
    struct CTNode *next;
} CTNode, *ChildPtr;

typedef struct CTBox
{
    TElemType data;
    ChildPtr FirstChild;
} CTBox;

typedef struct CTree
{
    CTBox nodes[MAXTREESIZE];
    int root, num;
} CTree;
