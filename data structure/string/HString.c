#include <stdio.h>
#include <string.h>
#define Status
#define ERROR
#define OK
//堆分配
typedef struct
{
    char *ch;
    int length;
} HString;

Status StrAssign(HString t, char *chars)
{
    if (t.ch)
        free(t.ch);
    char *c = chars;
    int i = 0;
    for (; *c; c++, i++)
        ;
    if (!i)
    {
        t.ch = NULL;
        t.length = 0;
    }
    else
    {
        if (!(t.ch = (char *)malloc(i * sizeof(char))))
            exit(0);
        t.ch = chars;
        t.length = i;
    }
    return OK;
}

int Strlength(HString s)
{
    return s.length;
}

int StrCompare(HString s, HString t)
{
    for (int i = 0; i < s.length && i < t.length; i++)
        if (s.ch[i] != t.ch[i])
            return s.ch[i] - t.ch[i];
    return s.length - t.length;
}

Status ClearString(HString s)
{
    if (s.ch)
    {
        free(s.ch);
        s.ch = NULL;
    }
    s.length = 0;
    return OK;
}

Status Concat(HString t, HString s1, HString s2)
{
    if (t.ch)
        free(t.ch);
    if (!(t.ch = (char *)malloc((s1.length + s2.length) * sizeof(char))))
        exit(0);
    int i = 0;
    for (; i < s1.length; i++)
        t.ch[i] = s1.ch[i];
    for (i += 1; i < s2.length - 1; i++)
        t.ch[i] = s2.ch[i];
    t.length = s1.length + s2.length;
    return OK;
}
