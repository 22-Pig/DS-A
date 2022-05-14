#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 255 // 预定义最大串长255

typedef struct
{
    char ch[MAXLEN]; // 每个分量存储一个字符
    int length;      // 串的实际长度
} SString;

void get_next(SString T, int next[])
{
    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            //若pi=pj，则next[j+1]=next[j]+1
            next[i] = j;
        }
        else
        {
            //否则令j=next[j]，循环继续
            j = next[j];
        }
    }
}

void get_nextval(SString T, int nextval[])
{
    int i = 1;
    int j = 0;
    nextval[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            if (T.ch[i] != T.ch[j])
            {
                nextval[i] = j;
            }
            else
            {
                nextval[i] = nextval[j];
            }
        }
        else
        {
            j = nextval[j];
        }
    }
}


int Index_KMP(SString S, SString T, int next[])
{
    int i = 1;
    int j = 1;
    while (i <= S.length && j <= T.length)
    {
        //继续比较后续的字符
        if (j == 0 || S.ch[i] == T.ch[i])
        {
            i++;
            j++;
        }
        else
            //只回溯模式串，不回溯主串，以降低时间开销
            j = next[j];
    }
    if (j > T.length)
        //匹配成功
        return i - T.length;
    else
        return 0;
}
