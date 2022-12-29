#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Stackinitsize 100
#define Stackincement 10

typedef struct Postype
{
    int i, j;
    // int flag;
} Postype;

typedef struct
{
    int ord;
    struct Postype seat;
    int di;
} Selemtype;

typedef struct
{
    Selemtype *base;
    Selemtype *top;
    int stacksize;
} Sqstack;

Sqstack Initstack(Sqstack s)
{
    s.base = (Selemtype *)malloc(Stackinitsize * sizeof(Selemtype));
    if (!s.base)
        exit(0);
    s.top = s.base;
    s.stacksize = Stackinitsize;
    return s;
}

Selemtype Gettop(Sqstack s, Selemtype e)
{
    if (s.base == s.top)
        exit(0);
    e = *(s.top - 1);
    return e;
}

int stackempty(Sqstack s)
{
    if (s.base == s.top || s.base == NULL)
        return 1;
    else
        return 0;
}

Sqstack push(Sqstack s, Selemtype e)
{
    if (s.top - s.base >= s.stacksize)
    {
        s.base = (Selemtype *)realloc(s.base, (s.stacksize + Stackincement) * sizeof(Selemtype));
        if (!s.base)
            exit(0);

        s.top = s.base + s.stacksize;
        s.stacksize += Stackincement;
    }
    *s.top++ = e;
    return s;
}

Selemtype h;
Sqstack pop(Sqstack s)
{
    if (s.base == s.top)
        exit(0);
    h = *--s.top;
    return s;
}

Sqstack clearstack(Sqstack s)
{
    s.base = s.top;
    return s;
}

int stackLength(Sqstack s)
{
    int len;
    len = s.top - s.base;
    return len;
}

void printstack(Sqstack s)
{
    if (s.base == s.top)
        exit(0);
    Selemtype *p = s.base;
    while (p + 1 != s.top)
    {
        printf("(%d,%d,%d),", p->seat.i, p->seat.j, p->di);
        p++;
    }
    printf("(%d,%d,%d)", p->seat.i, p->seat.j, p->di);
}

Selemtype Initselem(int a, int b)
{
    Selemtype t;
    t.seat.i = a;
    t.seat.j = b;
    // t.seat.flag=0;
    int ord = 0;
    int di = 0;
    return t;
}

Postype NextPos(Postype seat, int m)
{
    switch (m)
    {
    case 1:
        seat.j++;
        break;
    case 2:
        seat.i++;
        break;
    case 3:
        seat.j--;
        break;
    case 4:
        seat.i--;
        break;
    default:
        break;
    }
    return seat;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    Postype start, end;
    scanf("%d%d", &start.i, &start.j);
    // int p,q;
    scanf("%d%d", &end.i, &end.j);

    int **maze;
    maze = (int **)malloc(sizeof(int *) * (m + 2));
    for (int k = 0; k < m + 2; k++)
    {
        maze[k] = (int *)malloc(sizeof(int) * (n + 2));
    }
    /*int maze[m + 2][n + 2];
    for (int i = 0; i < m + 2; i++)
        for (int j = 0; j < n + 2; j++)
            maze[i][j] =0;*/
    for (int b = 0; b < n + 2; b++)
    {
        maze[0][b] = 1;
        maze[m + 1][b] = 1;
    }
    for (int a = 0; a < m + 2; a++)
    {
        maze[a][0] = 1;
        maze[a][n + 1] = 1;
    }
    for (int a = 1; a <= m; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            scanf("%d", &maze[a][b]);
        }
    }
    /*for(int a=0;a<=m+1;a++){
        for(int b=0;b<=n+1;b++)
        if(maze[a][b]==1)printf("##");
        else printf("[]");
        printf("\n");
    }
    */
    Sqstack s = Initstack(s);
    Postype cur = start;
    int curstep = 1;
    Selemtype e;
    do
    {
        /*printf("%d ",cur.i);
        printf("%d\n",cur.j);*/

        if (maze[cur.i][cur.j] == 0)
        {
            maze[cur.i][cur.j] = 2;
            e.ord = curstep;
            e.di = 1;
            e.seat = cur;
            s = push(s, e);
            // printf("o%do",stackempty(s));
            if (cur.i == end.i && cur.j == end.j)
            {
                printstack(s);
                return 0;
            }
            else
            {
                cur = NextPos(cur, 1);
                curstep++;
            }
        }

        else
        {
            if (!stackempty(s))
            {
                s = pop(s);
                while (h.di == 4 && !stackempty(s))
                {
                    maze[h.seat.i][h.seat.j] = 3;
                    s = pop(s);
                }
                if (h.di < 4)
                {
                    h.di++;
                    s = push(s, h);
                    cur = NextPos(h.seat, h.di);
                    curstep++;
                }
            }
        }
    } while (!stackempty(s));
    printf("no\n");
    return 0;
}
