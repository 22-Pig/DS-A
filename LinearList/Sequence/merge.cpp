#include <stdio.h>
#define MaxSize 10 // 定义最大长度

typedef int ElemType; // 定义ElemType为int类型

typedef struct
{
    ElemType data[MaxSize]; // 用静态的"数组"存放数据元素
    int length;             // 顺序表的当前长度
} SqList;                   // 顺序表的类型定义

/* 基本操作--初始化一个顺序表 */
void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0; // 将所有元素设置为默认初始值
    }
    L.length = 0; // 顺序表初始长度为0
}

void Traversal(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

/* 合并两个有序顺序表 */
bool Merge(SqList A, SqList B, SqList &C)
{
    if (A.length + B.length > 10)
    {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        if (A.data[i] <= B.data[j])
        {
            C.data[k++] = A.data[i++];
        }
        else
        {
            C.data[k++] = B.data[j++];
        }
    }
    printf("%di %dj %dk \n", i, j, k);

    /* if (i > j)
    {
        for (; j < B.length; j++)
            C.data[k++] = B.data[j];
    }
    else
    {
        for (; i < A.length; i++)
            C.data[k++] = A.data[i];
    } */
    while (i < A.length)
    {
        C.data[k++] = A.data[i++];
    }
    while (j < B.length)
    {
        C.data[k++] = B.data[j++];
    }

    C.length = k;
    return true;
}

int main(int argc, char const *argv[])
{
    SqList A;
    InitList(A);
    SqList B;
    InitList(B);
    SqList C;
    InitList(C);
    printf("输入A：\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &A.data[i]);
        A.length++;
    }
    Traversal(A);
    printf("输入B：\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &B.data[i]);
        B.length++;
    }
    Traversal(B);

    bool flag = Merge(A, B, C);
    if (!flag)
        printf("error\n");
    else
    {
        Traversal(C);
    }
    return 0;
}
