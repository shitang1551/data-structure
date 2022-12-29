#include <stdio.h>
#define Maxstrlen 255
#define Status int
#define ERROR 0
#define OK 1
typedef unsigned char SString[Maxstrlen + 1];

Status Concat(SString t, SString s1, SString s2)
{
    int i = 1;
    if (s1[0] + s2[0] <= Maxstrlen)
    {

        for (; i <= s1[0]; i++)
            t[i] = s1[i];
        for (i += 1; i <= s2[0]; i++)
            t[i] = s2[i];
        t[0] = s1[0] + s2[0];
    }
    else if (s1[0] < Maxstrlen)
    {
        for (; i <= s1[0]; i++)
            t[i] = s1[i];
        for (i += 1; i <= Maxstrlen - s1[0]; i++)
            t[i] = s2[i];
        t[0] = Maxstrlen;
    }
    else
    {
        for (; i <= Maxstrlen; i++)
            t[i] = s1[i];
        t[0] = Maxstrlen;
    }
}

Status SubString(SString sub, SString s, int pos, int len)
{
    if (pos < 1 || pos > s[0] || len < 0 || len > s[0] - pos + 1)
    {
        return ERROR;
    }
    for (int i = 1; i <= len; i++)
        sub[i] = s[pos + i - 1];
    sub[0] = len;
    return OK;
}

//模式匹配
int index(SString s, SString t, int pos)
{
    int i = pos;
    int j = 1;
    while (i <= s[0] && j <= t[0])
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > t[0])
        return i - t[0];
    else
        return 0;
}

// KMP
void get_next(SString t, int next[])
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i < t[0])
    {
        if (j == 0 || t[i] == t[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int index_KMP(SString s, SString t, int pos)
{
}
