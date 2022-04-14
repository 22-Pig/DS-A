#include <stdio.h>
#define MaxSize 10 // 定义最大长度

typedef struct
{
    int data[MaxSize]; // 用静态的"数组"存放数据元素
    int length;        // 顺序表的当前长度
} SqList;              // 顺序表的类型定义

/* 基本操作--初始化一个顺序表 */
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = i; // 将所有元素设置为默认初始值
    }
    L.length = MaxSize; // 顺序表初始长度为0
}

bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    if (L.length >= MaxSize)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i - 1];

    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int main()
{
    SqList L;    //声明一个顺序表
    InitList(L); // 初始化顺序表
    int e = -1;

    if (ListInsert(L, 3, 3))
    {
        printf("插入成功\n");
    }
    else
    {
        printf("插入失败\n");
    }

    if (ListDelete(L, 3, e))
    {
        printf("删除成功：%d\n", e);
    }
    else
    {
        printf("删除失败\n");
    }

    for (int i = 0; i < L.length; i++)
    {
        /* code */
        printf("data[%d]=%d\n", i, L.data[i]);
    }
    printf("%d", L.length);

    return 0;
}
