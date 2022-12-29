#include <stdarg.h>

#define MAXARRAYDIM 8
#define ElemType
#define Status
typedef struct
{
    ElemType *base;
    int dim;
    int *bounds;
    int *constants;
} Array;

Status InitArray(Array a, int dim)
{
    if (dim < 1 || dim > MAXARRAYDIM)
        return 0;
    a.dim = dim;
    a.bounds = (int *)malloc(dim * sizeof(int));
    if (!a.bounds)
        exit(0);
}