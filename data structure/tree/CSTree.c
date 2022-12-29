#include <string.h>
#include <string.h>
#include <stdlib.h>
#define MAXTREESIZE 100
#define TElemType

typedef struct CSNode
{
    TElemType data;
    struct CSNode *FirstChild, *NextSibling;
} CSNode, *CSTree;
