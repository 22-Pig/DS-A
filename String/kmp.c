#include <stdio.h>
#include <string.h>

void Next(char *T, int *next)
{
    int i = 1;
    int j = 0;
    next[1] = 0;
    while (i < strlen(T))
    {
        if (j == 0 || T[i - 1] == T[j - 1])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

void Nextval(char *T, int *nextval)
{
    int i = 1;
    int j = 0;
    nextval[1] = 0;
    while (i < strlen(T))
    {
        if (j == 0 || T[i - 1] == T[j - 1])
        {
            ++i;
            ++j;
            if (T[i] != T[j])
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

int KMP(char *S, char *T)
{
    int nextval[10];
    Nextval(T, nextval); //根据模式串T,初始化nextval数组
    
    int i = 1;
    int j = 1;
    while (i <= strlen(S) && j <= strlen(T))
    {
        // j==0:代表模式串的第一个字符就和当前测试的字符不相等；S[i-1]==T[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
        if (j == 0 || S[i - 1] == T[j - 1])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j]; //如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
        }
    }
    if (j > strlen(T))
    { //如果条件为真，说明匹配成功
        return i - (int)strlen(T);
    }
    return -1;
}
int main()
{
    int i = KMP("ababcabcacbab", "abcac");
    printf("%d", i);
    return 0;
}