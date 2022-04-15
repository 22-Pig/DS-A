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
        L.data[i] = 0; // 将所有元素设置为默认初始值
    }
    L.length = 0; // 顺序表初始长度为0
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

int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
        return 0;
    }
}

int main()
{
    SqList L;    //声明一个顺序表
    InitList(L); // 初始化顺序表

    /* 插入 */
    for (int i = 1; i <= 10; i++)
    {
        if (ListInsert(L, i, i))
        {
            // printf("插入成功\n");
        }
        else
        {
            printf("%d插入失败\n", i);
        }
    }
    printf("插入完成的长度:%d\n", L.length);

    /* 删除 */
    int e = -1; // 用变量把删除的元素带回来
    if (ListDelete(L, 1, e))
    {
        printf("删除成功：%d\n", e);
    }
    else
    {
        printf("删除失败\n");
    }
    printf("删除完成的长度:%d\n", L.length);

    /* 按值查找 */
    int e1 = LocateElem(L, 2);
    printf("位序%d:\n", e1);

    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}
