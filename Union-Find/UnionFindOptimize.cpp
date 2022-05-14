#include <stdio.h>
#include <stdlib.h>

#define SIZE 13

int UFSets[SIZE]; // 集合元素数组

/* 初始化并查集 */
void Initial(int S[])
{
    for (int i = 0; i < SIZE; i++)
    {
        S[i] = -1;
    }
}

/* 核心思想:尽可能让树变矮 */

/* Find "查"操作，先找到根结点，再进行"压缩路径" */
int Find(int S[], int x)
{
    int root = x;
    while (S[root] >= 0) // 循环找到根
    {
        root = S[root];
    }
    while (x != root) // 压缩路径
    {
        int t = S[x]; // t指向x的父结点
        S[x] = root;  // x直接挂到根结点下
        x = t;
    }

    return root; // 返回根结点编号
}

/* Union "并"操作，小树合并到大树 */
void Union(int S[], int Root1, int Root2)
{
    // 要求Root1与Root2是不同的集合
    if (Root1 == Root2)
    {
        return;
    }
    if (S[Root2] > S[Root1]) // Root2结点数更少
    {
        S[Root1] += S[Root2]; // 累加结点总数
        S[Root2] = Root1;     // 小树合并到大树
    }
    else
    {
        S[Root2] += S[Root1]; // 累加结点总数
        S[Root1] = Root2;     // 小树合并到大树
    }
}