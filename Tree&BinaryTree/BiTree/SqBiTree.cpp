#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef int ElemType;

struct TreeNode
{
    ElemType value; // 结点中的数据元素
    bool isEmpty;   // 结点是否为空
};

TreeNode t[MaxSize];

void init()
{
    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;
    }
}