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

/* 对长度为n的顺序表L，编写一个时间复杂度O（n），空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素。 */
void Del_x_1(SqList &L, ElemType x)
{
    int k = 0; // 用k纪录值不为x的数据元素的个数
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++; // 不等于k的元素增1
        }
    }
    L.length = k; // 顺序表的长度等于k
}

void Del_x_2(SqList &L, ElemType x)
{
    int k = 0; // 用k纪录值为x的数据元素的个数
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == x)
            k++;
        else
            L.data[i - k] = L.data[i]; // 当前元素前移k个位置
    }
    L.length = L.length - k; // 顺序表的长度-k
}

/* 从有序顺序表中删除值在给定值s和t(s<t)之间的所有元素，如果 s或t不合理或顺序表为空，则显示出错信息并退出程序。 */
bool Del_s_t_1(SqList &L, ElemType s, ElemType t)
{
    // 删除有序顺序表L中s和t之前的所有元素
    int i, j;
    if (s >= t || L.length == 0)
        return false;
    for (i = 0; i < L.length && L.data[i] < s; i++)
        ;              // 寻找大于等于s的第一个元素
    if (i == L.length) // 所有值均小于s
        return false;
    for (j = i; j < L.length && L.data[j] <= t; j++)
        ; // 寻找大于t的第一个元素
    for (; j < L.length; i++, j++)
        L.data[i] = L.data[j]; // 向前移，直接赋值
    L.length = i;
    return true;
}

bool Del_s_t_2(SqList &L, ElemType s, ElemType t)
{
    // 删除顺序表L中值在给定值s与t之间（要求s<t）的所有元素
    int i, k = 0;

    if (L.length == 0 || s >= t)
        return false; // 线性表为空或s、t不合法，返回

    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s && L.data[i] <= t)
            k++;
        else
            L.data[i - k] = L.data[i]; // 当前元素前移k个位置
    }

    L.length -= k; // 长度减小
    return true;
}

/* 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。 */
bool Del_Same(SqList &L)
{
    if (L.length == 0)
    {
        return false;
    }
    int i, j; // i存储第一个不相同的元素，j为工作指针
    for (i = 0, j = 1; j < L.length; j++)
    {
        if (L.data[i] != L.data[j]) // 查找下一个与上个元素值不同的元素
        {
            L.data[++i] = L.data[j]; // 找到后，则将元素前移
        }
    }
    L.length = i + 1;
    return true;
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
    printf("依次输入要往线性表中输入的元素：\n");
    for (int i = 0; i < MaxSize; i++)
    {
        scanf("%d", &L.data[i]);
        L.length++; // 每输入一个数顺序表的当前长度加1
    }
    printf("顺序表中现有的数据为：");
    Traversal(L);

    /* int ret;
    DelMin(L, ret);
    printf("顺序表中最小值为:%d\n", ret); */

    /* printf("删除顺序表中的最小值元素结点：");
    Traversal(L); */

    /* ReverseList(L);
    printf("顺序表逆序：");
    Traversal(L); */

    /* Del_x_1(L, 2);
    printf("删除值为x的元素：");
    Traversal(L); */

    /* bool flag1 = Del_s_t_1(L, 4, 8);
    if (!flag1)
        printf("数据不合理或顺序表为空，请检查后重试！\n");
    else
    {
        printf("删除4-8之间的元素之后顺序表元素为：");
        Traversal(L);
        printf("当前线性表的长度为：%d\n", L.length);
    } */

    /* bool flag2 = Del_s_t_1(L, 2, 4);
    if (!flag2)
        printf("数据不合理或顺序表为空，请检查后重试！\n");
    else
    {
        printf("删除2-4之间的元素之后顺序表元素为：");
        Traversal(L);
        printf("当前线性表的长度为：%d\n", L.length);
    } */

    /* printf("去重结果：");
    bool flag3 = Del_Same(L);
    if (!flag3)
        printf("顺序表为空，请检查后重试！\n");
    else
    {
        Traversal(L);
    } */

    

    return 0;
}
