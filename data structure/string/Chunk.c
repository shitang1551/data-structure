#define chunksize 80
typedef struct Chunk
{
    char cb[chunksize];
    struct Chunk *next;
} Chunk;
typedef struct
{
    Chunk *head, *tail;
    int curlen;
} LString;
//块链存储
