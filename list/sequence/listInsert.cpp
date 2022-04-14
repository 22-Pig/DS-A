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

int main()
{
    SqList L;    //声明一个顺序表
    InitList(L); // 初始化顺序表
    bool ret;
    ret = ListInsert(L, 3, 3);
    if (ret)
    {
        printf("123");
    }

    for (int i = 0; i < L.length; i++)
    {
        /* code */
        printf("data[%d]=%d\n", i, L.data[i]);
    }
    printf("%d", L.length);

    return 0;
}
