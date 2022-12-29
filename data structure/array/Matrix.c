#define Maxsize 12500
#define ElemType
typedef struct
{
    int i, j;
    ElemType e;
} Triple;
typedef struct
{
    Triple data[Maxsize + 1];
    int mu, nu, tu;
} TSMatrix;
