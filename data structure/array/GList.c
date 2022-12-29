#define AtomType

typedef enum
{
    ATOM,
    LIST
} ElemTag;
typedef struct GLnode
{
    ElemTag tag;
    union
    {
        AtomType atom;
        struct
        {
            struct GLnode *hp, *tp;
        } ptr;
    };
} * GList;
