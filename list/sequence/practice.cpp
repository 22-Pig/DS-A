/* 从顺序表中删除具有最小值的元素，并由函数返回被删元素的值，
空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行 */
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

/* 删除顺序表中的最小值元素结点，并通过引用型参数value返回其值 */
bool DelMin(SqList &L, ElemType &ret)
{
    if (L.length == 0)
    {
        return false; // 表空，中止操作返回
    }
    ret = L.data[0];
    int sub = 0;                       // 假定0号元素的值最小
    for (int i = 1; i < L.length; i++) // 循环，寻找具有最小值的元素
    {
        if (L.data[i] < ret)
        {
            ret = L.data[i]; //让 ret始终记忆当前具有最小值的元素
            sub = i;
        }
        L.data[sub] = L.data[L.length - 1]; // 空出的位置由最后一个元素填补
        L.length--;
        return true; // 此时ret即为最小值
    }
}

/* 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1) */
void ReverseList(SqList &L)
{
    ElemType temp; // 辅助变量
    for (int i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i];                     // 将前半部分元素放入辅助变量
        L.data[i] = L.data[L.length - 1 - i]; // 将后半部分元素放在前半部分空间中
        L.data[L.length - 1 - i] = temp;      // 从辅助变量中取出前半部分元素放入后半部分中
    }
}

/* 遍历顺序表 */
void Traversal(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    SqList L;    // 声明一个顺序表
    InitList(L); // 初始化顺序表
    for (int i = 0; i < MaxSize; i++)
    {
        scanf("%d", &L.data[i]);
        L.length++; // 每输入一个数顺序表的当前长度加1
    }
    int ret;
    DelMin(L, ret);
    printf("顺序表中最小值为:%d\n", ret);

    printf("删除顺序表中的最小值元素结点：");
    Traversal(L);

    ReverseList(L);
    printf("顺序表逆序：");
    Traversal(L);
    return 0;
}
